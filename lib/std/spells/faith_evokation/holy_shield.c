/*  Holy Shield
 *  Rebalanced by Dylanthalus@Haven April 11, 1999
 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("holy shield");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED);
  SetDifficulty(25);
  SetSkills( ([
      "faith" : 10,
      "evokation" : 10,
    ]) );
  SetMessages( ({
    ({ "", "A shield of %^YELLOW%^holy light%^RESET%^ surrounds "
           "$target_name." }),
    ({ "", "The %^YELLOW%^holy light%^RESET%^ around $agent_name "
           "deflects some of $target_possessive_noun attacks." }),
    ({ "", "The %^RED%^holy light%^RESET%^ around $agent_name disappears." }),
    }) );
  SetHelp(
     "This spell creates a minor magical field, protecting the target from "
     "all types of damage for the duration of the shield.");
  }
