/*  Aura v 2.0
 *  Coded for Haven 
 *  Rebalanced: Jan 26, 1999 - Dylanthalus@Haven
 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("chill aura");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED);
  SetDifficulty(10);
  SetSkills( ([
    "necromancy" : 40,
    ]) );
  SetMessages( ({
    ({ "", "A %^BLUE%^chill aura%^RESET%^ wisps around $target_name." }),
    ({ "", "The wispy %^BLUE%^ chill aura%^RESET%^ around $agent_name negates some of the power from $target_possessive_noun attack." }),
    ({ "", "The %^RED%^chill aura%^RESET%^ around $agent_name fades." }),
    }) );
  SetHelp(
   "This is the special necromantic spell researched by a lady of special talents. Her golden touch created "
   "a minor ability to give off a chill warding aura that prevents attacks from reaching their fullest potential."
   );
  SetUniqueSpell(1);
}
