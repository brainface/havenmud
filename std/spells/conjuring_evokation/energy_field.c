/*  Energy Field spell
    coded by Duuktsaryth@Haven
    rebalanced by Dylanthalus@Haven 04/10/99 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("energy field");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetSkills( ([
    "conjuring" : 80,
    "evokation" : 80,
    ]) );
  SetDifficulty(50);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED);
  SetMessages( ({
    ({ "", "A powerful %^YELLOW%^field of energy%^RESET%^ glows "
           "into being around $target_name." }),
    ({ "strike", "The %^YELLOW%^field%^RESET%^ around "
           "$agent_name blinks as $target_name $target_verb it." }),
    ({ "", "A %^RED%^field of energy%^RESET%^ around $agent_name "
           "shimmers away." }),
    }) );
   SetHelp(
    "This shield spell creates a field of energy around the target which "
    "protects against damage until the duration of the spell ends."
   );
 }
