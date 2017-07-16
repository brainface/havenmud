/*  
   Capsule spell  
   Coded by Duuktsaryth@Haven
   Rebalanced by Dylanthalus@Haven
   Jan 29th, 1999
*/
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("capsule");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetSkills( ([
    "conjuring" : 20,
    "evokation" : 20,
    ]) );
  SetDifficulty(25);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED);
  SetMessages( ({
    ({ "", "A %^YELLOW%^capsule of magical energy%^RESET%^ surrounds $target_name, protecting $target_objective from harm." }),
    ({ "strike", "The %^YELLOW%^capsule of energy%^RESET%^ around $agent_name bends as $target_name $target_verb it." }),
    ({ "", "A %^RED%^capsule of energy%^RESET%^ around $agent_name shimmers away." }),
    }) );
  SetHelp(
   "This more advanced shield spell creates a capsule of energy around the caster for a "
   "period of time."
   );
}
