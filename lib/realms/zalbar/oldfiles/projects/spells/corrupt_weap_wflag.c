#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_SPELL;

int eventEndImbue(object);

static void create() {
  spell::create();
  SetSpell("corrupt weapon");
  SetRules("OBJ");
  SetMagicCost(120, 100);
  SetSpellType(SPELL_OTHER);
  SetDifficulty(125);
  SetReligions("Saahagoth");
  SetSkills( ([
      "faith" : 125,
      "necromancy" : 125,
    ]) );
  SetHelp(
          "Allows a follower of Saahagoth to corrupt a weapon , causing it to "
          "burst into black flames that do not harm the wielder but inflict "
          "heat damage to victims of the weapon.");
  }

int CanCast(object who, int level, mixed limb, object *targets){
    object thing;
    thing = targets[0];    

    if(!sizeof(targets)){
        message("", "Cast corrupt weapon on what?", who);
        return 0;
    }

    if (thing->GetProperty("weapon_imbue")){
        message("", "That weapon has already been altered with the powers "
        "of the gods!", who);
        return 0;
    }

    if (!(thing->GetVendorType() & VT_WEAPON)){
        message("", "You cannot corrupt something that is not a weapon!", who);
        return 0;
    }
  
    return spell::CanCast(who, level, limb, targets);
}

varargs int eventCast(object who, int level, mixed blah, object *targets) {
  int time, dmg;
  object thing = targets[0];
  object thing2 = targets[0];
  
  object *hurt = filter(all_inventory(environment(who)), (: living :) );
  hurt = filter(hurt, (: noncreatorp :) );
  time = level + (who->GetSkillLevel("necromancy"))/2;
  dmg = thing->GetDamageType();
  if (time < 200) {time = 200;}
  call_out( (: eventEndImbue, thing2, dmg, thing:), time);

// FUMBLE
  if (!(random(to_int(100)))) {
     send_messages( "scream",
      "$agent_name $agent_verb as $target_name %^BOLD%^%^RED%^EXPLODES%^RESET%^ "
      "sending small fragments ripping through the air, harming all in the room.",
        who, thing, environment(who)
  );
    thing->eventDestruct();
    hurt->AddHealthPoints(-250);
  return 1;
  }
 else{

// SUCCESS 
 
  send_messages( "mumble",
       "$agent_name $agent_verb a small prayer causing $target_name to "
       "be consumed in an %^BOLD%^%^BLACK%^unholy black%^RESET%^ flame, "
       "which envelopes " + thing->GetShort() + " completely. %^BOLD%^%^RED%^"
       "Thing2 " + thing2->GetShort() + "%^RESET%^. ",
        who, thing, environment(who)
  );
   thing->SetProperty("weapon_imbue", 1);
   thing->SetDamageType(HEAT|dmg);
   thing->SetShort(thing->GetShort() + " (ablazed)");
           
   return 1;
 }
}

int eventEndImbue(object who, int dmg, object who2) {     
     who->RemoveProperty("weapon_imbue");
     who->SetDamageType(dmg);
     
     send_messages("","%^BOLD%^%^YELLOW%^The black flames surrounding " +
       who->GetShort() + " withers and dies.%^RESET%^"
       "Thing2 " + who2->GetShort() + ".",
       who, environment(who));
       return 1;
   }
