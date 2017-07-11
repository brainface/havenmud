/* General faith spell.  Amelia@Haven Dec '98
 * Rebalanced by Dylanthalus April 11, 1999
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("unholy guardian");
   SetRules("","LIV");
   SetSpellType(SPELL_DEFENSE);
   SetProtectionTypes(ALL_EXTERNAL);
   SetShieldType(SHIELD_TIMED);
   SetDifficulty(60);
   SetSkills( ([
     "faith"       : 250,
     "evokation"   : 250,
     ]) );
   SetMaximumMorality(0);
   SetMessages( ({
     ({ "","An %^BLACK%^BOLD%^unholy guardian%^RESET%^ appears on $target_possessive_noun shoulder.", }),
     ({ "","The %^BOLD%^BLACK%^unholy guardian%^RESET%^ flies in front of $target_possessive_noun attack!",}),
     ({ "","The %^BOLD%^BLACK%^unholy guardian%^RESET%^ on $agent_possessive_noun shoulder fades into %^RED%^nothingness%^RESET%^." }),
              }) );
  SetHelp(
      "Summoning the powers of darkness and evil, priests can use this spell to conjure forth a "
      "minor demon from the lower planes to sit upon his shoulder and intercept all damage from "
      "an external source for a limited time."
    ); 
}
