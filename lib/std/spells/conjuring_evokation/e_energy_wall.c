/* ----------------------------------------------------------------------- */
// Filename: enhanced_energy_wall.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Dec 3, 1998
// Abstract: The ultimate physical defense spell.
// Revision History: original code from energy wall by Malak@Haven
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetUniqueSpell(1);
  SetSpell("enhanced energy wall");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED);
  SetSkills( ([
     "conjuring" : 175,
     "evokation" : 175,
    ]) );
  SetDifficulty(85);
  SetMessages( ({
    ({ "", "A %^RED%^magnificient surging wall of energy %^RESET%^forms around $target_name." }),
    ({ "strike", "The %^RED%^magnificient surging wall of energy %^RESET%^ around $agent_name shimmers as $target_name $target_verb it." }),
    ({ "", "The %^RED%^wall of energy %^RESET%^around $agent_name disperses." }),
    }) );
  SetHelp(
     "This is an enhanced version of the earlier energy wall spell which blocks more "
     "damage than the lesser version."
    );
 }
