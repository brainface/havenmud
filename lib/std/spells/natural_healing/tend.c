/*    /spells/tend.c
 * Created by Duuktsaryth@Haven
 * Balanced by Duuktsaryth@Haven 090897
 * Re-balanced by Rhakz@Haven
 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
    spell::create();
    SetSpell("tend wounds");
    SetRules("", "LIV");
    SetAutoHeal(1);
    SetSpellType(SPELL_HEALING);
    SetSkills( ([
      "healing" : 1,
      "natural magic" : 1,
    ]) );
    SetDifficulty(5);
    SetMessages(({ ({ "are", "$target_name $target_verb no better off." }),
		   ({ "are", "$target_name $target_verb looking a bit "
			  "better." }),
                   ({ ({ "mend", "provide" }), "$agent_name $agent_verb "
					       "$target_name and "
					       "$agent_verb $target_objective "
					       "with more life." }) }));
  SetHelp(
	    "This spell does light healing on a target, or yourself if "
	    "you specify no target.");
}


/* Approved by Duuktsaryth on Tue Sep  9 02:02:44 1997. */
