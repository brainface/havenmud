/*  Midlevel def spell by Malak 
    ReBalanced by Dylanthalus@Haven Feb 11/99 */

#include <magic.h>
#include <lib.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("sphere");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_DAMAGE);
  SetDifficulty(10);
  SetSkills( ([
    "evokation" : 40,
    "conjuring" : 40,
    ]) );
  SetMessages( ({
  ({ "", "A solid %^BLUE%^sphere%^RESET%^ forms around $target_name." }),
  ({ "", "$agent_possessive_noun %^BLUE%^sphere of energy%^RESET%^ gets hit by $target_name." }),
  ({ "", "The solid %^RED%^sphere%^RESET%^ of energy around $agent_name collapses." }),
  }) );
  SetHelp(
    "This damage-based shield creates a small sphere of energy around the target."
  );
}
