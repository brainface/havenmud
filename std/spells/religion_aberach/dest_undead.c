// Title: Aberac Clerical Spells
// File: dest_undead.c
// Author: Timothy Morris aka Morgoth@Haven
// Date: July 1998
//
// Abstract:	A spell that damages or destroys undead creatures
//
// Revision History: 
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
	spell::create();
	SetSpell("destroy undead");
	SetRules("", "LIV");
	SetSpellType(SPELL_COMBAT);
	SetRequiredMagic(70);
	SetSkills( ([ 
     "faith" : 35,
       "necromancy" : 35,
		]) );
  SetMaximumMorality(-200);
	SetDifficulty(25);
  SetReligions( ({ "Aberach" }) );
	SetMorality(-10);
	SetDamageType(COLD);
  SetEnhanceSkills( ({ "ice magic" }) );
  SetHelp(
		"The caster uses their knowledge of necromancy to "
		"channel their magical energy into an attempt to destroy "
		"the forces animating a dead creature. If the caster "
		"is powerful enough, the abomination will be destroyed, "
		"otherwise it will be severely weakened.");
	}

varargs int eventCast(object who, int level, mixed limb, object array targets) {
	object target = targets[0];
	if( target->GetUndead() && target->GetLevel() <= who->GetLevel() * 2) {
		if( target->GetLevel() < (((who->GetLevel() *
				who->GetSpellLevel("destroy undead")) / 100) / 2)) {
			send_messages(({"grasp","let","sever"}),
				"%^BOLD%^BLUE%^The "
				"area darkens suddenly as $agent_name $agent_verb "
				"$target_name with an evil gleam in $agent_possessive "
				"eye. $target_name $target_verb out a horrible "
				"shriek as $agent_name $agent_verb the unearthly "
				"energies holding $target_name together, leaving "
				"$target_possessive useless remains to collapse "
				"to the ground.%^RESET%^", who, target,
				environment(who));
			target->eventDie(who);
			}
		else {
			int damage;
			if( level <= 10 )
				damage = GetDamage(level);
			else
				damage = (target->GetHealthPoints() *
						(who->GetSpellLevel("destroy undead") - 10)) /
						100;
			if( target->GetHealthPoints() * 100 <=
				(target->GetHealthPoints() * 100) / 10 )
				damage = GetDamage(level);
			switch(level) {
				case 26..50 :
					send_messages(({"grab","attempt","succeed"}),
						"%^CYAN%^Grinning evilly, "
						"$agent_name $agent_verb ahold of "
						"$target_name and $agent_verb to destroy "
						"$target_objective but $agent_verb only in "
						"seriously weakening $target_objective.%^RESET%^",
						who, target, environment(who));
					break;
				case 51..75 :
					send_messages(({"grab","attempt","succeed"}),
						"%^BOLD%^BLUE%^Grinning evilly, "
						"$agent_name $agent_verb ahold "
						"of $target_name and $agent_verb to destroy "
						"$target_objective but $agent_verb only in "
						"massively weakening $target_objective."
						"%^RESET%^", who, target, environment(who));
					break;
				case 76..100 :
					send_messages(({"grab","attempt","bring"}),
						"%^BLUE%^Grinning evilly, "
						"$agent_name $agent_verb ahold of "
						"$target_name and $agent_verb to destroy "
						"$target_objective but, failing that, "
						"$agent_verb $target_objective to the "
						"verge of destruction.%^RESET%^",
						who, target, environment(who));
					break;
				default :
					send_messages(({"grab","attempt","succeed"}),
						"%^BOLD%^CYAN%^Grinning evilly, "
						"$agent_name $agent_verb "
						"ahold of $target_name and $agent_verb to "
						"destroy $target_objective but $agent_verb "
						"only in weakening $target_objective.%^RESET%^",
						who, target, environment(who));
				}
			target->eventReceiveDamage(who, MAGIC, damage, 1, 0);
			}
		}
	else {
		if( who->GetLevel() < target->GetLevel() / 2 ) {
			int damage;
			send_messages(({"grab","attempt","are"}),
				"%^BOLD%^RED%^Grinning evilly, $agent_name "
				"$agent_verb ahold of $target_name and $agent_verb "
				"destroy $target_objective but $target_name "
				"$target_verb much too powerful for $agent_name to "
				"handle, and the spell flashes back, wounding "
				"$agent_objective.%^RESET%^", who, target,
				environment(who));
			damage = GetDamage(level) + 10 * (target->GetLevel() % who->GetLevel());
			who->eventReceiveDamage(0, MAGIC, damage, 1, 0);
			}
		else {
			send_messages(({"grab","attempt","take"}),
				"%^YELLOW%^Grinning evilly, "
				"$agent_name $agent_verb ahold of "
				"$target_name and $agent_verb to destroy "
				"$target_objective. But since $target_name is "
				"not undead $target_nominative only $target_verb a "
				"small amount of damage from the raw energy of the "
				"spell.%^RESET%^", who, target, environment(who));
			target->eventReceiveDamage(who, MAGIC, GetDamage(level), 1, 0);
			}
		}
	return 1;
	}


/* Approved by Morgoth on Wed Aug  5 15:40:40 1998. */
