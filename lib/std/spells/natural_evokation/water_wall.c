// mahkefel 2010
// A lowbie timed shield for droods
#include <magic.h>
#include <lib.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("water wall");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetSkills( ([
      "natural magic" : 40,
      "evokation" : 40,
  ]) );
  //SetMagicCost(10,20);
  SetDifficulty(25);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED);
  SetMessages( ({
    ({ "",
      "A %^BOLD%^%^BLUE%^wall of water%^RESET%^ rises from the ground "
      "and engulfs $target_name."
    }),
    ({ "",
      "The water flowing around $agent_name "
      "%^BOLD%^%^BLUE%^soaks%^RESET%^ $target_possessive_noun attack."
    }),
    ({ "",
      "The %^BOLD%^%^BLUE%^wall of water%^RESET%^ around $agent_name crashes "
      "to the floor with a loud splash."
    }),
    }) );
  SetHelp(
    "This spell summons a stream of water to engulf the caster or target "
    "and protect them from all damage for a period of time."
  );
}

