//--  Torak@Haven   --//
//-- Wards of Light --//
//--   Enchanter    --//

#include <magic.h>
#include <lib.h>
#include <damage_types.h>
inherit LIB_SPELL;
int AttackResponse(object who, object agent, int x, class MagicProtection mp);

static void create() {
  ::create();
  SetSpell("wards of light");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED);
  SetDifficulty(66);
  SetUniqueSpell(1);
  SetHelp(
    "This being one of the more powerful of the Mage's "
    "protection spells, creates a dancing aura of radiant, "
    "multicolor light that surrounds the caster, protecting "
    "the caster from a great deal of damage that is not from "
    "a weapon."
    );
  SetSkills( ([
    "evokation"  : 500,
    "conjuring"  : 500,
    ]) );
  SetMessages( ({
    ({ "", 
       "A dancing aura of %^RED%^m%^MAGENTA%^u%^BLUE%^l%^CYAN%^t%^GREEN%^i%^RESET%^%^YELLOW%^c%^ORANGE%^o%^RED%^l%^MAGENTA%^o%^BLUE%^r%^RESET%^ "
       "light appears around $target_name." }),
    ({ "",
    "The dancing aura of "
       "%^RED%^m%^MAGENTA%^u%^BLUE%^l%^CYAN%^t%^GREEN%^i%^RESET%^"
       "%^YELLOW%^c%^ORANGE%^o%^RED%^l%^MAGENTA%^o%^BLUE%^r%^RESET%^ "
    "light around $agent_name flickers with $target_possessive_noun "
    "attack." }),
    ({ "", "The dancing aura of light around $agent_name "
       "shines brightly for a few moments, then fades away." }),
    }) );
  }
