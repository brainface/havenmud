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
   SetSpell("funeral pyre");
   SetRules("");

   SetEnhanceSkills( ({ "fire magic" }) );
   SetSkills( ([
     "conjuring" : 170,
     "necromancy" : 170,
     ]) );
   SetDamageType(HEAT);
   SetStaminaCost(75, 75);
   SetAutoDamage(0);
   SetAreaSpell(1);
   SetSpellType(SPELL_COMBAT);
   SetDifficulty(100);
   SetMessages(({ ({"", "$agent_possessive_noun funeral pyre %^GREEN%^comfortably warms%^RESET%^ $target_name." }),
                  ({"", "$agent_possessive_noun funeral pyre %^RED%^scorches%^RESET%^ $target_name." }),
                  ({"", "$agent_possessive_noun funeral pyre %^BOLD%^RED%^engulfs%^RESET%^ $target_name in cleansing flame!" })
                   }));
  SetHelp(
    "This incantation forms a hastily made but effective burial rite for "
    "entire groups of beings that are not quite willing to die without a "
    "strong convincing."
  );
}

int eventCast(object who, int level, mixed limb, object array targets) {
   send_messages("",
     "%^BLACK%^The ground around $agent_name erupts in cleansing flame!%^RESET%^",
     who, who, environment(who) );
   return spell::eventCast(who, level, limb, targets);
}

