/* ----------------------------------------------------------------------- */
// Filename: temp_shield.c
// Creation Date: Unknown
// Original Creator: Unknown
// Version coded by: Dylanthalus@Haven
// Abstract: Temperature Shield v 3.0
// Balanced by: Dylanthalus@Haven
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
   ::create();
   SetSpell("temperature shield");
   SetRules("","LIV");
   SetSpellType(SPELL_DEFENSE);
   SetProtectionTypes(ALL_EXTERNAL);
   SetShieldType(SHIELD_DAMAGE);
   SetDifficulty(135);
   SetSkills( ([
     "conjuring" : 225,
     "evokation" : 225,
     ]) );
   SetMessages( ({
        ({ "are","$target_name $target_verb surrounded by a %^BOLD%^GREEN%^temperature shield%^RESET%^." }),
        ({ "strike","The %^BOLD%^GREEN%^temperature shield%^RESET%^ around $agent_name wavers as $target_name $target_verb it." }),
        ({ "","The %^BOLD%^RED%^temperature shield%^RESET%^ ceases to exist." }),
        }) );
  SetHelp(
    "This shield is a high level shield of alternating heat and cold which protects the target from "
    "all damage while it lasts.  This shield is damage-based and will take a limited amount of abuse "
    "before collapsing."    
    );
}
