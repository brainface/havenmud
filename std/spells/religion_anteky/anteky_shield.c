/*  Protect v 2.0 for Haven
 *  Coded by Duuktsaryth
 *  SetDetailHelp() by Ranquest 02/06/99
 *	Rebalanced by Dylanthalus April 11/99
 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("burning aura");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_DAMAGE);
  SetMagicCost(10, 10);
  SetSkills( ([
     "faith"       : 1,
     "evokation" : 1,
    ]) );
  SetDifficulty(25);
  SetReligions( ({ "Anteky" }) );
  SetMessages( ({
    ({ "", "A %^BOLD%^RED%^burning aura%^RESET%^ appears around $target_possessive_noun body." }),
    ({ "strike", "The %^BOLD%^RED%^burning aura%^RESET%^ around $agent_name flickers as $target_name $target_verb it." }),
    ({ "", "The %^RED%^burning aura%^RESET%^ around $agent_name is extinguished." }),
    }) );
  SetHelp(
	 "This spell surrounds the target in a luminous burning aura. This aura protects "
	 "poorly but protects against all forms of damage. Priests of Anteky use it as their "
	 "early form of defense before learning more powerful incantations later in their "
	 "faith development."
	 );
 }
