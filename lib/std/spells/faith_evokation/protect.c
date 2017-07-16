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
  SetSpell("protect");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
    SetShieldType(SHIELD_TIMED);
  SetSkills( ([
     "faith" : 1,
     "evokation" : 1,
    ]) );
  SetDifficulty(15);
  SetMessages( ({
    ({ "", "A %^BOLD%^YELLOW%^shield of protection%^RESET%^ "
           "suddenly appears around $target_possessive_noun body." }),
    ({ "strike", "The %^BOLD%^YELLOW%^shield of protection%^RESET%^ "
           "around $agent_name wavers "
           "as $target_name $target_verb it." }),
    ({ "", "The %^RED%^shield of protection%^RESET%^ around $agent_name "
           "vanishes." }),
    }) );
  SetHelp(
	        "A magical defense spell that allows the caster to create "
           "a glowing shield around the target to protect them from all "
           "types of damage. The shield absorbs damage until it is destroyed.");
 }
