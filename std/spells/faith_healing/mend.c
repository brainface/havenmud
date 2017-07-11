/*    /spells/mend.c
 *    From Nightmare LPMud
 *    Created by Descartes of Borg 961102
 * Balanced to Haven Standards 090897
 * Duuktsaryth@Haven
 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() 
{
  spell::create();
  SetSpell("mend");
  SetRules("", "LIV");
  SetAutoHeal(1);
  SetSpellType(SPELL_HEALING);
  SetSkills( ([
     "healing" : 20,
     "faith"   : 20,
  ]) );
  SetDifficulty(20);
  SetMorality(3);
  SetMessages(({ ({ "are", "$target_name $target_verb no better off." }),
    ({ "are", "$target_name $target_verb looking a bit better." }),
    ({ ({ "mend", "provide" }), "$agent_name $agent_verb $target_name "
      "and $agent_verb $target_objective with more life." }) }));
  SetHelp(
     "This spell does healing on a target, or yourself if "
     "you specify no target.");
}


/* Approved by Duuktsaryth on Mon Sep  8 14:27:43 1997. */
