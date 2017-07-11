/*  Buffer v 2.0 for Haven
 *  Coded by Duuktsaryth
 *  Rebalanced: Jan 26, 1999 - Dylanthalus@Haven
 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("bunnies");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_DAMAGE);
  SetReligions("Eclat");
  SetSkills( ([
    "natural magic" : 1,
    "evokation"     : 1,
    ]) );
  SetDifficulty(10);
  SetMessages( ({
    ({ "", "A family of %^BOLD%^WHITE%^fluffy bunnies%^RESET%^ arrives to protect $target_name." }),
    ({ "", "The %^BOLD%^WHITE%^fluffy bunnies%^RESET%^ protecting $agent_name block a mean old attack." }),
    ({ "", "The %^RED%^fluffy bunnies%^RESET%^ protecting $agent_name scamper back to their burrow." }),
    }) );
  SetHelp(
   "This \"shield\" spell summons a burrow of bunnies to defend the target from harm. They will only "
   "accept so much punishment before fleeing back to their warm, safe burrow."
   );
 }
