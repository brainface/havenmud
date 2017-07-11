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
  SetSpell("lightning shield");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED);
  SetSkills( ([
     "faith"     : 40,
     "evokation" : 40,
    ]) );
  SetDifficulty(30);
  SetReligions("Damhair");
  SetMessages( ({
    ({ "", "A %^BOLD%^YELLOW%^shimmer of lightning%^RESET%^ "
           "crackles into being around $target_possessive_noun body." }),
    ({ "hit", "The %^BOLD%^YELLOW%^lightning shield%^RESET%^ "
           "around $agent_name crackles loudly "
           "as $target_name $target_verb it." }),
    ({ "", "The %^YELLOW%^lightning shield%^RESET%^ around $agent_name "
           "is completely dispersed." }),
    }) );
  SetHelp(
	        "A magical defense spell that allows the caster to create "
          "a shield of lightning around the person named.");
 }
