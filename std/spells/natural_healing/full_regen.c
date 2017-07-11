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
  SetSpell("full regeneration");
  SetRules("", "LIV");
  SetAutoHeal(1);
  SetSpellType(SPELL_HEALING);
  SetSkills( ([
    "healing"       : 100,
    "natural magic" : 100,
   ]) );
  SetDifficulty(55);
  SetMessages( ({ 
    
    ({ "are",   "$target_name $target_verb mildly healed by $agent_possessive_noun magic." }),
	  ({ "regenerate",  "$agent_name $agent_verb the flesh covering $target_possessive_noun wounds." }),
    ({ "cause", "$agent_name $agent_verb flesh to regrow over $target_possessive_noun deepest wounds." }) 
    
    }));
  SetHelp(
	    "This spell heals a target greatly, or yourself if you specify no target."
	    );
}