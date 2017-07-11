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
  SetSpell("aura");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED);
  SetDifficulty(10);
  SetSkills( ([
    "conjuring" : 10,
    "evokation" : 10,
    ]) );
  SetMessages( ({
    ({ "", "A flickering %^BLUE%^aura%^RESET%^ appears around $target_name." }),
    ({ "", "The flickering %^BLUE%^aura%^RESET%^ around $agent_name deflects some of the power from $target_possessive_noun attack." }),
    ({ "", "The %^RED%^aura%^RESET%^ around $agent_name disappears." }),
    }) );
  SetHelp(
   "This is the second shield spell taught to most evokers. It is different "
   "from buffer by virtue of being the first timed shield spell. Rather than "
   "absorbing a specific amount of damage and then dispersing, the shield "
   "takes a standard amount of abuse every hit until the spell automatically "
   "disperses itself at the end of its duration."
   );
  }
