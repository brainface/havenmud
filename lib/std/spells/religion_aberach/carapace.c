// Title: Aberac Clerical Spells
// File: carapace.c
// Author: Tim Morris aka Morgoth@Haven
// Date: July 1998
//
// Abstract: 
//
// Revision History: 
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

int carapaceHit(object who, object agent, int x, class MagicProtection carapace);
void carapaceEnd(object who);

static void create() {
	spell::create();
	SetSpell("carapace");
	SetRules("", "LIV");
	SetSpellType(SPELL_DEFENSE);
	SetProtectionTypes(ALL_EXTERNAL);
	SetShieldType(SHIELD_DAMAGE);
	SetSkills( ([
		"faith" : 1,
		"necromancy" : 1,
		]) );
	SetDifficulty(10);
  SetHelp(
		"Uses the necromantic powers of the caster to "
		"create a thick carapace of spiky bone around the target. "
		"Due to the mastery of undead bestowed upon the "
		"followers of Aberach the carapace is especially "
		"resistant to damage dealt by the living dead.");
  SetReligions( ({ "Aberach" }) );
  SetMessages( ({
    ({ ({}), "A %^BOLD%^CYAN%^carapace of thick, spike covered bone%^RESET%^ appears over $target_possessive_noun body." }),
    ({ }),
    ({ }),
    }) );
}


int hitCallback(object who, object agent, int x, class MagicProtection carapace) {
	object caster = carapace->caster;
	
	if( agent->GetUndead() ) {
		send_messages(({}), "The %^BOLD%^BLUE%^necromantic power "
			"%^RESET%^of the %^BOLD%^CYAN%^carapace%^RESET%^ nullifies "
			"much of the power of $agent_possessive_noun "
			"attack.", agent, who, environment(who));
		carapace->absorb += ( random(x) / 3 );
		return x;
		}
	send_messages(({"are"}), "$agent_name "
		"$agent_verb showered with %^BOLD%^CYAN%^spikes "
		"and sharp fragments of bone%^RESET%^ as $agent_possessive "
		"attack hits the %^BOLD%^CYAN%^carapace%^RESET%^ "
		"around $target_name.", agent, who, environment(who));
	return x;
	}

void endCallback(object who) {
	if( who )
		send_messages(({}), "The %^BOLD%^CYAN%^carapace%^RESET%^ "
			"around $agent_name %^RED%^crumbles%^RESET%^ "
			"and falls to the ground.", who, 0, environment(who));
	}
