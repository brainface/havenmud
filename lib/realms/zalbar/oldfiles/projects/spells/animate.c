/* Animate dead */
// Summary: animate dead spell for necros
// Date: ???
// Created by: Judging for the balance, Duuk ;)
// Minor fixes by: Rhakz@Haven
// Fixed to have zombie follow and assist caster
// Laoise, August 2004

#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include <daemons.h>
#include <magic.h>
inherit LIB_SPELL;

void CrumbleCorpse(object corpse);

static void create() {
  ::create();
  SetSpell("animate dead");
  SetSpellType(SPELL_OTHER);
  SetRules("OBJ");
  SetSkills( ([
    "necromancy" : 1,
    "conjuring"  : 1,
     ]) );
  SetMagicCost(  100, 100);
  SetStaminaCost(100, 100);
  SetDifficulty(50);
  SetHelp("This spell summons the power of the caster into "
          "one mystical force to reinstall motion to an "
          "undead form. This is not a resurrection spell, "
          "but actually restores a mindless life to a corpse "
          "that then becomes the caster's tool. \n"
          "%^BLACK%^%^B_RED%^DO NOT animate a second corpse if one is already active!%^RESET%^");
}

object *GetTargets(object who, mixed args...) {
  object *targets = ::GetTargets(who, args...);
  if (!targets) targets = ({ });
  filter(targets, (: $1->GetCorpseState() :) );
  return targets;
}

varargs int CanCast(object who, int level, mixed x, object *targets) {
  object ob;
  if (who->GetProperty("animate_zombie")) {
    if (find_object(who->GetProperty("animate_zombie"))) {
      who->eventPrint("%^RED%^Your attempts to dominate more than one corpse result in a hideous backlash!%^RESET%^");
      who->eventReceiveDamage(load_object(STD_DUMMY "magicshock"), MAGIC, (who->GetLevel() + 1) * 5, 1);
      return 0;
    }
  }
  foreach(object t in targets) {
    if (t->GetUserCorpse()) {
      who->eventPrint(t->GetShort() + " cannot be animated.");
      return 0;
    }
  }
  return ::CanCast(who, level, x, targets);
}

varargs int eventCast(object who, int level, mixed x, object *targets) {
  object zombie;
  object t = targets[0];
  int zombielevel;
  
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
         break;
      case "rotted corpse" :
         zombie->SetShort("a rotting animated " + corpse->GetRace() + " zombie");
         zombie->SetId( ({ corpse->GetId()...,  "zombie", corpse->GetRace() }) );
         zombie->SetAdjectives( ({ corpse->GetAdjectives()..., "undead", "rotting", "animated" }) );
         zombie->SetKeyName("rotting " + corpse->GetRace());
      case "skeleton" :
         zombie->SetUndeadType("skeleton");
         zombie->SetShort("a skeletal " + corpse->GetRace());
         zombie->SetId( ({ corpse->GetId()...,  "skeleton",  corpse->GetRace() }) );
         zombie->SetAdjectives( ({ corpse->GetAdjectives()..., "undead", "skeletal", "animated" }) );
         zombie->SetKeyName("skeletal " + corpse->GetRace());
         break;
      }
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
   return 1;      
  }
}
