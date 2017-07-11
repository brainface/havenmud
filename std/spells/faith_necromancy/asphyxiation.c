//
// The 'asphyxiation' spell
// Created by Zaxan@Haven
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("asphyxiation");
  SetRules("","LIV");
  SetSpellType(SPELL_COMBAT);
  SetEnhanceSkills( ({ "poison magic" }) );
  SetSkills( ([
     "necromancy" : 20,
     "faith"      : 20,
  ]) );
  SetMorality(-5);
  SetDifficulty(27);
  SetAutoDamage(1);
  SetDamageType(POISON);
  SetMessages( ({ 
    ({ "shake", "$target_possessive_noun throat begins to shrink, but $target_nominative quickly $target_verb it off." }),
		({ "choke", "$target_name $target_verb in pain from a slight loss of air." }),
		({ "attempt", "$target_possessive_noun eyes begin to bulge from $target_possessive head as $target_nominative $target_verb to breathe." }),
		({ "", "$target_possessive_noun throat completely closes up, causing $target_objective to fall to the ground in extreme pain." }) }));
  SetHelp(
	   "This spell uses the power forces of necromancy to attempt to "
	   "choke the caster's target, forcing them to struggle for air, "
	   "making it hard to concentrate on anything else. If cast "
	   "without a target, the spell will be directed at your current "
	   "enemy.");
}


/* Approved by Balishae on Sun Jan 11 19:35:07 1998. */
