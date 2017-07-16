//
// The 'lava storm' spell
// Created by Zaxan@Haven
//
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("lava storm");
   SetRules("");
   
   SetEnhanceSkills( ({ "fire magic" }) );
   SetSkills( ([
     "conjuring" : 60,
     "evokation" : 60,
     ]) );
   SetDamageType(HEAT);
   SetStaminaCost(50, 50);
   SetAutoDamage(0);
   SetAreaSpell(1);
   SetSpellType(SPELL_COMBAT);
   SetDifficulty(100);
   SetMessages(({ ({"", "$agent_possessive_noun %^RED%^lava storm%^RESET%^ misses $target_name." }),
                  ({"", "$agent_possessive_noun %^RED%^lava storm%^RESET%^ slightly burns $target_name." }),
                  ({"", "$agent_possessive_noun lava storm severely chars $target_possessive_noun skin." })
                   }));
  SetHelp(
           "This spell summons a huge lava storm that will sweep "
           "through the entire area hitting everyone except the "
           "caster."
           );
}

int eventCast(object who, int level, mixed limb, object array targets) {
   send_messages("",
     "%^RED%^The air smells of fire and brimstone as a lava storm sweeps through the area.%^RESET%^",
     who, who, environment(who) );
   return spell::eventCast(who, level, limb, targets);
}
