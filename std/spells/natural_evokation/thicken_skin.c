/*  Thicken Skin, a natural-only spell 
    rebalanced by Dylanthalus@Haven 6/May/99 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("thicken skin");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetSkills( ([
    "evokation"     : 15,
    "natural magic" : 15,
    ]) );
  SetDifficulty(20);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_DAMAGE);
  SetMessages( ({
   ({ "", "$target_possessive_noun skin seems to %^GREEN%^thicken%^RESET%^." }),
    ({ "", "$agent_possessive_noun skin %^GREEN%^deflects%^RESET%^ some "
           "of the damage from $target_possessive_noun attack." }),
    ({ "", "$agent_name skin seems to %^RED%^thin%^RESET%^." }),
    }) );
  SetHelp(
           "By utilizing the sometimes harsh elements of nature, the natural "
           "magic user is able to thicken their skin using this spell.  The "
           "effects of which allows the caster or targeted creature to be "
           "protected against an amount of physical and magical damage.");           
 }
