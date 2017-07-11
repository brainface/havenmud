// Title: Aberach Clerical Spells
// File: flame_grasp.c
// Author: Timothy Morris aka Morgoth@Haven
// Date: July 1998
//
// Abstract:	A basic first level flame based attack spell
//
// Revision History: 
// Changed from faith/evok to faith/necro, because all other 'goth
// spells are faith/necro - Laoise
// Somehow this spell ended up in Aberach
// aberach is ice boosted, not fire boosted
// restored to goths by Torak 2012

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
	spell::create();
	SetSpell("flaming grasp");
	SetRules("", "LIV");
	SetSpellType(SPELL_COMBAT);
	SetRequiredMagic(20);
	SetSkills( ([ 
       "faith" : 20,
         "necromancy" : 20,
		]) );
  SetMaximumMorality(-200);
	SetDifficulty(5);
  SetReligions( ({ "Saahagoth" }) );
  SetEnhanceSkills( ({ "fire magic" }) );
	SetMorality(0);
	SetAutoDamage(0);
	SetDamageType(HEAT);
	SetMessages(({ 
	  ({ ({"reach","dodge"}), 
            "$agent_name $agent_verb for $target_name but $target_nominative $target_verb the attack." }),
		({ "grasp", 
		  "$agent_name $agent_verb $target_name with %^BOLD%^RED%^flaming hands%^RESET%^, %^BOLD%^YELLOW%^singeing%^RESET%^ $target_objective slightly." }),
		({ "grasp",
		  "$agent_name $agent_verb $target_name with %^BOLD%^RED%^flaming hands%^RESET%^, %^RED%^scorching%^RESET%^ $target_objective badly." }),
		({ "grasp", 
		  "$agent_name $agent_verb $target_name with %^BOLD%^RED%^flaming hands%^RESET%^, %^BOLD%^RED%^burning%^RESET%^ $target_objective horribly." })
		}));
  SetHelp(
		"Allows the caster to use the flames of the lower "
		"planes to attempt to burn his target.");
}
