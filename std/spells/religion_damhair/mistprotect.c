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
  SetSpell("protective mists");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_DAMAGE);
  SetSkills( ([
     "faith"     : 5,
     "evokation" : 5,
    ]) );
  SetDifficulty(20);
  SetReligions("Damhair");
  SetMessages( ({
    ({ "", "A %^BOLD%^BLUE%^mist of protection%^RESET%^ "
           "swirls into being around $target_possessive_noun body." }),
    ({ "strike", "The %^BOLD%^YELLOW%^mist of protection%^RESET%^ "
           "around $agent_name disperses lightly "
           "as $target_name $target_verb it." }),
    ({ "", "The %^BLUE%^protective mist%^RESET%^ around $agent_name "
           "is completely dispersed." }),
    }) );
  SetHelp(
	        "A magical defense spell that allows the caster to create "
          "a protective mist around the person named.");
 }
