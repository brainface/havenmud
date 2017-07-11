/* Dylanthalus@Haven 12 Dec 1998 
 * rebalanced by Dylanthalus 6 May 1999 */

#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("natural veil");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetSkills( ([
    "evokation"     : 40,
    "natural magic" : 40,
    ]) );
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_DAMAGE);
  SetDifficulty(25);
  SetMessages( ({
    ({ "", "A pulsating %^GREEN%^natural veil%^RESET%^ appears "
           "around $target_name." }),
    ({ "", "The pulsating %^GREEN%^natural veil%^RESET%^ "
           "shields $agent_name from $target_possessive_noun attack." }),
    ({ "", "The %^RED%^natural veil%^RESET%^ around $agent_name "
           "ceases to exist." }),
    }) );
  SetHelp(
          "This spell harnesses natural energy and shapes "
          "it into a shield that will defend the targeted "
          "creature from a fair amount of external damage.");
  }


/* Approved by Dylanthalus on Sat Dec 12 08:56:15 1998. */
