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
  SetSpell("seal flesh");
  SetRules("", "LIV");
  SetAutoHeal(1);
  SetSpellType(SPELL_HEALING);
  SetSkills( ([
    "healing" : 40,
    "natural magic" : 40,
   ]) );
  SetDifficulty(25);
  SetMessages( ({ 
    
    ({ "are",   "$target_name $target_verb no better off." }),
	  ({ "seal",  "$agent_name $agent_verb the flesh covering $target_possessive_noun wounds." }),
    ({ "cause", "$agent_name $agent_verb flesh to regrow over $target_possessive_noun deepest wounds." }) 
    
    }));
  SetHelp(
	    "This spell does moderate healing on a target, or yourself if you specify no target."
	    );
}
