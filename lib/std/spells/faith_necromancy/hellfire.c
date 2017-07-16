//
// The 'hellfire' spell
// Created by Zaxan@Haven
//
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("hellfire");
   SetRules("");
   SetSkills( ([ 
      "faith"      : 50,
      "necromancy" : 50,
      ]) );
   SetDamageType(HEAT);
   SetEnhanceSkills( ({ "fire magic" }) );
   SetStaminaCost(20,10);
   SetAutoDamage(0);
   SetAreaSpell(1);
   SetSpellType(SPELL_COMBAT);
   SetDifficulty(30);
   SetMessages( ({ 
      ({"", "$agent_possessive_noun %^RED%^hellfire%^RESET%^ "
            "doesn't even touch $target_name." }),
      ({"", "$agent_possessive_noun %^RED%^hellfire%^RESET%^ "
            "touches $target_name, slightly burning "
            "$target_objective." }),
      ({"", "$agent_possessive_noun %^RED%^hellfire%^RESET%^ "
            "completely covers $target_name, scorching "
            "$target_possessive skin to a crisp." }),
      }) );
  SetHelp(
           "This spell summons a huge fire from the deep depths of "
           "the lower planes that sweeps through the entire area hitting "
           "everyone except the caster. ");
}

int eventCast(object who, int level, mixed limb, object array targets) {
   send_messages( "",
     "%^RED%^Suddenly, a huge fire spawned from dark depths sweeps through the area.%^RESET%^",
     who, targets, environment(who));
   return spell::eventCast(who, level, limb, targets);
}
