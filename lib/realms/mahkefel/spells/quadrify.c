/* Quadrify */
// an enchanter spell used to make furniture
// mounts, and or a pet

#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include <daemons.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("quadrify");
  SetSpellType(SPELL_OTHER);
  SetRules("OBJ");
  SetSkills( ([
    "conjuring"   : 120,
    "enchantment" : 120,
    
  ]) );
  SetMagicCost(  100, 100);
  SetStaminaCost(100, 100);
  SetDifficulty(50);
  SetHelp(
    "A legendary enchanter can utilize their magic to transform a mundane "
    "item into a better, four-legged mundane item, sometimes even breathing "
    "false life into the object.");
}

varargs int CanCast(object who, int level, mixed q, object *t) {
  object target = t[0];
  
  if (living(t)) {
    who->eventPrint("Unfortunately, even your magic can't improve "+t->GetName());
    return 0;
  } else if (t->PreventGet()) {
    who->eventPrint("That's either too big or too stable for you to change.")
    return 0;
  } else if (t->GetProperty("magic")) {
    who->eventPrint("That item is too full of magic already to quadrify.")
    return 0;
  }

  if ( sizeof(t->GetMaterials()) < 1) {
    who->eventPrint("That appears to be made of nothing and you can make nothing from it.");
    return 0;   
  }  
  
  if ( member_array("textile", t->GetMaterials()) != -1) {
    object *dags =  children(DIR_SPELLS "/obj/quadrify/dag");
    foreach(object dag in dags) {
      if(dag->GetOwner() = who->GetKeyName()) {
        who->eventPrint("You already have enough dags!");
        return 0;
      }
    }    
  }
  
  if ( member_array("metal", t->GetMaterials()) != -1) {
    object *dags =  children(DIR_SPELLS "/obj/quadrify/horse");
    foreach(object dag in dags) {
      if(dag->GetOwner() = who->GetKeyName()) {
        who->eventPrint("You can only have one horse of course.");
        return 0;
      }
    }    
  }
  
  if ( member_array("metal", t->GetMaterials() == -1 &&
       member_array("textile", t->GetMaterials() == -1 &&
       member_array("wood", t->GetMaterials() == -1 &&
       member_array("leather", t->GetMaterials() == -1 &&
       member_array("natural", t->GetMaterials() == -1 ){
        who->eventPrint("This is made of some strange stuff, and your magic can't affect it.");
        return 0;
         
       }
  // todo: check for other material types, no material types
}

varargs int eventCast(object who, int level, mixed x, object *targets) {
  object quad;
  object scrap = targets[0];
  int daglevel;
  
  
  

  
  foreach(object corpse in targets) {
    zombie = new(STD_SPELLS "obj/animate_zombie");
    if( !RACES_D->GetValidRace(corpse->GetRace()) ) {
      who->eventPrint(capitalize(corpse->GetShort()) + " refuses to be animated.");
      zombie->eventDestruct();
      continue;
     }

    zombie->SetUndead(1);
    zombie->SetUndeadType("zombie");
    zombie->SetGender(corpse->GetGender());
    zombie->SetRace(corpse->GetRace());
    zombie->SetClass(corpse->GetOriginalClass());
    zombie->SetLong("This is an animated corpse of " + add_article(corpse->GetRace()) +
                    " that has been summoned back into the material world.");
    switch(level) {
      case 0..20:
        zombielevel = who->GetLevel() - 50;
        break;
      case 21..50:
        zombielevel = who->GetLevel() - 20;
        break;
      case 51..100:
        zombielevel = who->GetLevel() - 10;
        break;
      }
    if (zombielevel < 1) zombielevel = 1;
    if (zombielevel > corpse->GetLevel() * 2) zombielevel = corpse->GetLevel() * 2;
    zombie->SetLevel(zombielevel);

    switch(corpse->GetCorpseState()) {
      case "fresh corpse" :
         zombie->SetShort(add_article(corpse->GetRace()) + " zombie");;
         zombie->SetId( ({ corpse->GetId()..., "zombie", corpse->GetRace() }) );
         zombie->SetAdjectives( ({ corpse->GetAdjectives()..., "undead", corpse->GetRace() }) );
         zombie->SetKeyName("undead " + corpse->GetRace());
         zombie->SetResistances(BLUNT|SOUND,"low");
         zombie->SetResistances(SLASH|HEAT,"weakness");
         break;
      case "rotted corpse" :
         zombie->SetShort("a rotting animated " + corpse->GetRace() + "zombie");
         zombie->SetId( ({ corpse->GetId()...,  "zombie", corpse->GetRace() }) );
         zombie->SetAdjectives( ({ corpse->GetAdjectives()..., "undead", "rotting", "animated" }) );
         zombie->SetKeyName("rotting " + corpse->GetRace());
         zombie->SetResistances(BLUNT|SOUND,"low");
         zombie->SetResistances(SLASH|HEAT,"weakness");
         break;
      case "skeleton" :
/std/spells/necromancy/animate.c (62-122 77%):
         zombie->SetUndeadType("skeleton");
         zombie->SetShort("a skeletal " + corpse->GetRace());
         zombie->SetId( ({ corpse->GetId()...,  "skeleton",  corpse->GetRace() }) );
         zombie->SetAdjectives( ({ corpse->GetAdjectives()..., "undead", "skeletal", "animated" }) );
         zombie->SetKeyName("skeletal " + corpse->GetRace());
         zombie->SetResistances(ALL_ELEMENTS|PIERCE|SLASH,"low");
         zombie->SetResistances(BLUNT|SOUND,"weakness");
         break;
      }

      zombie->SetResistances(GAS|POISON|HUNGER|DISEASE,"immune");
   zombie->SetCapName(capitalize(zombie->GetKeyName()));
   foreach(object thing in all_inventory(corpse)) {
     thing->eventMove(zombie);
    }

   zombie->eventForce("wear all");
   send_messages( ({ "summon", "force" }),
     "$agent_name $agent_verb%^RED%^BOLD%^ power%^RESET%^ from "
     "$agent_reflexive and $agent_verb $target_name back into "
     "the world of the living.", who, corpse, environment(corpse) );
   corpse->eventDestruct();
   who->SetPermanentProperty("animate_zombie", file_name(zombie));
   zombie->SetOwner(who->GetKeyName());
   zombie->eventMove(environment(who));
   zombie->eventForce("emote blinks its eyes open.");
   zombie->eventForce("speak You... rang...?");
   zombie->eventForce("follow "+ who->GetKeyName());
   who->eventForce("lead "+ zombie->GetKeyName());
   zombie->eventForce("guard " + who->GetKeyName());
   zombie->SetReligion(who->GetReligion());
   return 1;
  }
}


