/*  Imbue Weapon Spell
 *  Thoin@Haven 11/29/05
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_SPELL;

int eventEndImbue(object);

static void create() {
  spell::create();
  SetSpell("imbue weapon");
  SetRules("OBJ");
  SetMagicCost(120, 100);
  SetSpellType(SPELL_OTHER);
  SetDifficulty(125);
  SetSkills( ([
      "faith" : 125,
      "enchantment" : 125,
    ]) );
  SetHelp(
          "Allows a Cleric to imbue a weapon with divine power for a "
          "period of time.");
  }

int CanCast(object who, int level, mixed limb, object *targets){
    object thing;
    thing = targets[0];    

    if(!sizeof(targets)){
        message("", "Cast imbue weapon on what?", who);
        return 0;
    }

    if (thing->GetProperty("weapon_imbue")){
        message("", "That weapon has already been imbued with the powers "
        "of the gods!", who);
        return 0;
    }

    if (!(thing->GetVendorType() & VT_WEAPON)){
        message("", "You cannot imbue something that is not a weapon!", who);
        return 0;
    }
  
    return spell::CanCast(who, level, limb, targets);
}

varargs int eventCast(object who, int level, mixed blah, object *targets) {
  int time, dmg;
  object thing = targets[0];
  object *hurt = filter(all_inventory(environment(who)), (: living :) );
hurt = filter(hurt, (: noncreatorp :) );
  time = level + (who->GetSkillLevel("enchantment"))/5;
  dmg = thing->GetDamageType();
  call_out( (: eventEndImbue, thing, dmg :), time);

  if (time < 60) {time = 60;}
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

switch(who->GetReligion()) {

 case "Aberach" :
  send_messages( "mumble",
       "$agent_name $agent_verb a small prayer causing $target_name to "
       "be consumed in an %^BOLD%^%^BLACK%^unholy black%^RESET%^ mist, "
       "which envelopes this instrument of divine wrath.",
        who, thing, environment(who)
  );
   thing->SetProperty("weapon_imbue", 1);
   thing->SetDamageType(ACID|dmg);
   return 1;
  break;

 case "Kylin" :
   send_messages("pray",
        "$agent_name $agent_verb to the all mighty and powerful Duuk. Suddenly "
        "$target_name is struck by a bolt of divine "
        "%^BOLD%^%^YELLOW%^light%^RESET%^. The air around this holy object "
        "becomes charged with energy.",
        who, thing, environment(who)
  );
   thing->SetProperty("weapon_imbue", 1);
   thing->SetDamageType(SHOCK|dmg);
   return 1;
  break;

 case "Kuthar" :
   send_messages("roar",
        "$agent_name $agent_verb with the terrifying might of a dragon "
        "causing $target_name to shake and then burst into "
        "%^BOLD%^%^RED%^flames%^RESET%^. The %^BOLD%^%^RED%^flames%^RESET%^ "
        "slowly envelope $target_name causing it to radiate heat.",
        who, thing, environment(who)
  );
   thing->SetProperty("weapon_imbue", 1);
   thing->SetDamageType(HEAT|dmg);
   return 1;
  break;

 default :
   send_messages("imbue",
        "Calling upon $agent_possessive god $agent_name $agent_verb "
        "$target_name with divine power, causing $target_name to "
        "%^BOLD%^%^WHITE%^shimmer%^RESET%^ slightly.",
        who, thing, environment(who)
  );
   thing->SetProperty("weapon_imbue", 1);
   thing->SetDamageType(MAGIC|dmg);     
   return 1;
  break;
  }
}
}
   int eventEndImbue(object who, int dmg) {     
  if (!who) return 0;
     who->RemoveProperty("weapon_imbue");
     who->SetDamageType(dmg);
     send_messages("",
       capitalize(who->GetShort()) + " returns to normal.",
       who, environment(who));
       return 1;
   }
