//--  Torak@Haven  --//
//-- Spiritual Aid --//
//--     Kuthar    --//

// edited by torak 10/28/12
#include <magic.h>
#include <lib.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("spiritual aid");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED);
  SetDifficulty(60);
  SetHelp(
    "Drawing on the power of the past, Kuthar shamans may recieve "
    "spiritual protection, protecting against all types of damage."
    );
  SetSkills( ([
     "faith" : 300,
     "natural magic" : 300,
     "evokation" : 300,
  ]) );
  SetMessages( ({
    ({ "raise", 
       "%^BOLD%^Chanting in a monotone voice, $agent_name "
       "slowly $agent_verb $agent_possessive arms high in a "
       "circle over $agent_possessive head, calling forth a "
       "swirling sphere of spirits to gather about "
       "$agent_objective.%^RESET%^"
    }),
    ({ "",
        "One of the %^BOLD%^spirits%^RESET%^ about $agent_possessive body "
        "%^BOLD%^CYAN%^glows brightly%^RESET%^ as it absorbs an attack "
        "directed at $agent_objective."
          }),
    ({ "", 
       "%^BOLD%^The spirits swirling about $agent_name return to "
       "their plane of existence.%^RESET%^" }),
    }) );
  }
