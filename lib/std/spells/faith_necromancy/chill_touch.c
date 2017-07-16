/*
 * The 'chill touch' spell
 * Created by Zaxan@Haven
 * 20th of May, 1997
 * Balanced to new specifics 3 Sept 1997
 * Duuktsaryth@Haven
 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;
static void create() {
spell::create();
	SetSpell("chill touch");
	SetRules("", "LIV");
	SetSpellType(SPELL_COMBAT);
  SetSkills( ([
   "necromancy" : 1,
   "faith"      : 1,
    ]) );
  SetDifficulty(10);
	SetAutoDamage(0);
	SetMorality(-2);
  SetDamageType(COLD);
  SetEnhanceSkills( ({ "ice magic" }) );
  SetMessages( ({
    ({ "touch", "$agent_name barely $agent_verb $target_name with $agent_possessive fingertips." }),
    ({ "chill", "$agent_name lightly%^BLUE%^ $agent_verb%^RESET%^ $target_name with a slight touch." }),
    ({ "grasp", "$agent_name%^BOLD%^BLUE%^ $agent_verb%^RESET%^ hold of $target_name with a chill touch!" }),
    }) );
  SetHelp(
		"This spell causes an enemy to suddenly feel cold and "
		"uncomfortable inside. If cast without a specified target "
		"while in combat, your current enemy will be targetted.");
}


/* Approved by Duuktsaryth on Wed Sep  3 13:08:26 1997. */
