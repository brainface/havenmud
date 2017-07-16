/* ----------------------------------------------------------------------- */
// Filename: mesmer_barrier.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: January 23rd, 1998
// Abstract: A High level all damage based protection shield for mages
// Last Rebalanced: 04/10/99 Dylanthalus@Haven
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("mesmer barrier");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetShieldType(SHIELD_TIMED);
  SetSkills( ([
    "conjuring" : 100,
    "evokation" : 100,
    ]) );
  SetDifficulty(120);
  SetProtectionTypes(ALL_EXTERNAL);
  SetMessages( ({
   ({ ({"open","create"}) , "$agent_name $agent_verb a rift to the planes of magic $agent_verb a %^MAGENTA%^mesmer barrier%^RESET%^ around $target_name." }),
   ({ "assault", "The %^RED%^mesmer barrier%^RESET%^ around $agent_name surges as $target_name $target_verb it." }),
    ({ "mesmer", "The %^ORANGE%^mesmer barrier %^RESET%^around $agent_name has been dispelled." }),
    }) );
 
  SetHelp(
    "This advanced timed shield creates a barrier of energy from the essence of the Lord of Magic."
    );    
}
