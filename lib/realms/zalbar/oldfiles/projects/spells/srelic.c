//
//  Summon Relic
//  Thoin@Haven 11/29/05
//
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_SPELL;

int eventSummonWeapon(string weapon);
int PickWeapon(string weapon);

static void create() {
  spell::create();
  SetSpell("summon relic of the faithful");
  SetRules("");
  SetMagicCost(120, 100);
  SetSpellType(SPELL_OTHER);
  SetDifficulty(175);
  SetSkills( ([
      "faith" : 175,
    ]) );
  SetHelp(
          "This spell allows a faithful to summon forth a divine weapon of their "
          "choice. Allowed weapons types are: slash, pierce, knife, pole, hack, "
          "melee, projectile, blunt.");
  }

varargs int eventCast(object who, int level, mixed b, object *targets) {
   object caster = who;
   object target = targets[0];

    message("my_action",
         "Please pick the weapon type you wish to summon "
         "or input 'exit' to cancel.",
         who);
       input_to( (: PickWeapon :) );
    return 1;
   }

int PickWeapon(string weapon) {
  object who = this_player();
  if(weapon=="exit") {return 0;}
  if(!(weapon == "knife" || weapon == "slash" || weapon == "blunt" ||
   weapon == "pole" || weapon == "pierce" || weapon == "hack" ||
   weapon == "projectile" || weapon == "melee")) {
    message("my_action",
      "That is not a valid weapon type. Please pick again or input 'exit' to "
      "cancel.", who);
    input_to( (: PickWeapon :) );
     return 1;
     }
  return eventSummonWeapon(weapon);
   }

int eventSummonWeapon(string weapon) {
object weaponobj;
object who = this_player();
  int time, dmg, level;
  level = who->GetSpellLevel("summon relic of the faithful");
  time = (level * 15 + 10 + who->GetSkillLevel("faith")/20);

// FUMBLE

  if (!(random(to_int(100)))) {
     send_messages( ({ "are", "collapse" }),
      "$agent_name $agent_verb surrounded by a brilliant light but then $agent_nominative "
      "suddenly $agent_verb to the ground.",
        who, 0, environment(who)
  );
    who->eventCollapse();
    who->AddMagicPoints(-250);
    who->AddHealthPoints(-250);
  return 1;
  }
 else{

// SUCCESS

switch(who->GetReligion()) {

 case "Aberach" :
  send_messages( ({"mumble", "find"}),
       "$agent_name $agent_verb a small prayer causing a shaft of "
       "%^BOLD%^%^BLACK%^unholy black%^RESET%^ light to split the sky. As "
       "the light fades, $agent_name $agent_verb that $agent_possessive prayers "
       "have been answered.",
        who, 0, environment(who)
  );
  weaponobj = new("/std/spells/obj/weapons/arelic"+weapon+".c");
  weaponobj->SetCountDown(10 + time);
  weaponobj->eventMove(who);
  weaponobj->SetMaster(who->GetKeyName());  
   return 1;
  break;

 case "Kylin" :
   send_messages( ({"pray", "find"}),
        "$agent_name $agent_verb to the all mighty and powerful Duuk. Suddenly "
        "a bolt of divine %^BOLD%^%^YELLOW%^light%^RESET%^ strikes $agent_name. "
        "As the light fades, $agent_name $agent_verb that $agent_possessive prayers "
        "have been answered.",
        who, 0, environment(who)
  );
  weaponobj = new("/std/spells/obj/weapons/krelic"+weapon+".c");
  weaponobj->SetCountDown(10 + time);
  weaponobj->eventMove(who);
  weaponobj->SetMaster(who->GetKeyName()); 
   return 1;
  break;

 case "Kuthar" :
   send_messages( ({"roar", "find" }),
        "$agent_name $agent_verb with the terrifying might of a dragon "
        "creating a pillar of %^BOLD%^%^RED%^flames%^RESET%^ to surround "
        "$agent_reflexive. As the %^RED%^flames%^RESET%^ fade, $agent_name "
        "$agent_verb the relic of the ancients.",
        who, 0, environment(who)
  );
  weaponobj = new("/std/spells/obj/weapons/kurelic"+weapon+".c");
  weaponobj->SetCountDown(10 + time);
  weaponobj->eventMove(who);
  weaponobj->SetMaster(who->GetKeyName());
   return 1;
  break;
  
 case "Saahagoth" :
   send_messages( ({"scream", "fall" }),
        "$agent_name $agent_verb in %^RED%^pain%^RESET%^ as $agent_nominative "
        "$agent_verb to the ground. %^RED%^Laughter%^RESET%^ echoes "
        "throughout the room and then the relic appears "
        "and whisper to $agent_name, go forth and kill in my name.",
        who, 0, environment(who)
  );
  weaponobj = new("/std/spells/obj/weapons/sarelic"+weapon+".c");
  weaponobj->SetCountDown(10 + time);
  weaponobj->eventMove(who);
  weaponobj->SetMaster(who->GetKeyName());
   return 1;
  break;
 
  case "Soirin" :
   send_messages( ({"moan", "collapse" }),
        "$agent_name $agent_verb in %^MAGENTA%^ecstasy%^RESET%^ as "
        "$agent_nominative $agent_verb to the ground in delight. As "
        "$agent_nominative stands a voice whispers, Lust may be "
        "the greatest desire but it is not the only one, go and seek all.",
        who, 0, environment(who)
  );
  weaponobj = new("/std/spells/obj/weapons/sorelic"+weapon+".c");
  weaponobj->SetCountDown(10 + time);
  weaponobj->eventMove(who);
  weaponobj->SetMaster(who->GetKeyName());
   return 1;
  break;
  
 default :
   send_messages("summon",
        "Calling upon $agent_possessive god $agent_name $agent_verb "
        "forth a divine relic.",
        who, 0, environment(who)
  );
  weaponobj = new("/std/spells/obj/weapons/drelic"+weapon+".c");
  weaponobj->SetCountDown(10 + time);
  weaponobj->eventMove(who);
  weaponobj->SetMaster(who->GetKeyName());     
   return 1;
  break;
  }
}
}
