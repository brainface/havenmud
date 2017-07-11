/*    /spells/fireball.c
 *    From Nightmare LPMud
 *    Created by Descartes of Borg 961027
 * Balanced to Haven 7 Sept 1997
 * Duuktsaryth @ Haven
 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("fireball");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
     "conjuring" : 50,
     "evokation" : 50,
    ]) );
  SetEnhanceSkills( ({ "fire magic" }) );
  SetDifficulty(20);
  SetMorality(0);
  SetAutoDamage(0);
  SetDamageType(HEAT);
  SetMessages(({ 
    ({ "accept", "$target_name $target_verb $agent_possessive_noun fireball with a smile." }),
		({ "are", "$target_name $target_verb slightly charred by $agent_possessive_noun fireball." }),
		({ "", "$agent_possessive_noun %^RED%^fireball%^RESET%^ lights $target_name on fire!" }),
		({ "are", "$target_name $target_verb burned to a crisp by $agent_possessive_noun %^BOLD%^RED%^fireball%^RESET%^." }) 
		}) );
   SetHelp(
	    "This spell conjures a tremendous fireball out of "
	    "thin air and sends it hurling towards an unsuspecting enemy.  "
	    "If cast without specifying a target while in combat, the "
	    "fireball is targetted at your current enemy.");
}


/* Approved by Duuktsaryth on Sun Sep  7 21:16:45 1997. */
