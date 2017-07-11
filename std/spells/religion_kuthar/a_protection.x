//--      Torak@Haven      --//
//-- Ancestrial Protection --//
//--         Kuthar        --//

#include <magic.h>
#include <lib.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("ancestral protection");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED);
  SetDifficulty(50);
  SetHelp(
    "Kuthar clerics, being so close to their ancestors of long "
    "past days, have been able to harness the power that remains of "
    "their ancesters to create a shimmering shield around them that "
    "protects the target from all damage.");
  SetSkills( ([
     "faith"     : 35,
     "natural magic" : 35,
    ]) );
  SetMessages( ({
    ({ "create", 
       "Using the powers of the ancients"
       ", $agent_name "
       "$agent_verb a shimmering shield around $target_name." }),
    ({ "strike",
    "The shimmering shield around $agent_name bends slightly as "
    "$target_name $target_verb it, and then snaps back in to place." }),
/*
    ({ "create", 
       "Using the powers of the ancients"
       ", $agent_name "
       "$agent_verb a shimmering shield around $target_name." }),
*/
    ({ "", "The shield around $agent_name "
       "fades away." }),
    }) );
  }
