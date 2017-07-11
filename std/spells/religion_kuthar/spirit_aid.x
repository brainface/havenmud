//--  Torak@Haven  --//
//-- Spiritual Aid --//
//--     Kuthar    --//

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
  SetDifficulty(25);
  SetHelp(
    "With this simple and low cost spell, Kuthar clerics can gain "
    "spiritual aid to protect vs physical damage.  It is their "
    "lowest shield spell.");
  SetSkills( ([
     "faith" : 5,
     "natural magic" : 5,
  ]) );
  SetMessages( ({
    ({ "create", 
       "Using the powers of the ancients"
       ", $agent_name "
       "$agent_verb a %^CYAN%^spiritual%^RESET%^ shield of protection."}),
    ({ "",
        "The %^CYAN%^spiritual%^RESET%^ shield around $agent_name vibrates "
          "as the attack crashes into it. "
          }),
    ({ "", "The %^RED%^spiritual%^RESET%^ shield around $agent_name "
       "fades away." }),
    }) );
  }
