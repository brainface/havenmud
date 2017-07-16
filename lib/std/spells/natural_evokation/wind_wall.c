// mahkefel 2010
// A lowbie timed shield for droods
#include <magic.h>
#include <lib.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("wind wall");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetSkills( ([
      "natural magic" : 20,
      "evokation" : 20,
  ]) );
  //SetMagicCost(10,20);
  SetDifficulty(25);
  SetProtectionTypes(ALL_PHYSICAL|GAS);
  SetShieldType(SHIELD_TIMED);
  SetMessages( ({
    ({ "",
      "A %^BOLD%^swift wind%^RESET%^ begins "
      "circling $target_name."
    }),
    ({ "",
      "The wind circling $agent_name "
      "%^BOLD%^deflects%^RESET%^ $target_possessive_noun attack."
    }),
    ({ "",
      "The %^BOLD%^swift wind%^RESET%^ around $agent_name suddenly calms."
    }),
    }) );
  SetHelp(
    "This spell summons a current of air to encircle the caster or target "
    "to protect them from physical attacks and deadly vapors."
  );
}

