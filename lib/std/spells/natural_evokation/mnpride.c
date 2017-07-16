//--  Ohtar@Haven   --//
//-- Mother Nature's Pride --//
//--   Natural Magic   --//

#include <magic.h>
#include <lib.h>
#include <damage_types.h>
inherit LIB_SPELL;
int AttackResponse(object who, object agent, int x, class MagicProtection mp);

static void create() {
  ::create();
  SetSpell("mother nature's pride");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED);
  SetDifficulty(75);
  SetUniqueSpell(1);
  SetHelp(
    "This is the most powerful shield the Natural Mage's "
    "can learn. The shield is created by drawing from mother"
    "nature, using all of her strengths to create a nearly "
    "impenetrable aura around the target protecting them from "
    "all damage for a length of time. "
    );
  SetSkills( ([
    "evokation"  : 350,
    "natural magic"  : 350,
    ]) );
  SetMessages( ({
    ({ "", 
 "A large flash of light %^BOLD%^%^YELLOW%^f%^GREEN%^l%^YELLOW%^o%^GREEN%^w%^YELLOW%^s%^RESET%^ "
 "through the air before wrapping $target_name with %^GREEN%^mother nature's pride%^RESET%^." }),
    ({ "",
    "The %^YELLOW%^p%^GREEN%^r%^YELLOW%^i%^GREEN%^d%^YELLOW%^e%^RESET%^ around "
    "$agent_name %^GREEN%^bends%^RESET%^ as $target_possessive_noun strikes it. "
 }),
    ({ "", "The pride around $agent_name %^CYAN%^glimmers%^RESET%^ briefly before fading from view." }),
    }) );
  }
