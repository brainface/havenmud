/*  Legendlevel buffertype spell
    ReBalanced by Dylanthalus@Haven Feb 11,99
 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
    ::create();
    SetSpell("energy wall");
    SetRules("", "LIV");
    SetSpellType(SPELL_DEFENSE);
    SetProtectionTypes(ALL_EXTERNAL);
    SetShieldType(SHIELD_TIMED);
    SetSkills( ([
      "conjuring" : 125,
      "evokation" : 125,
    ]) );
   SetDifficulty(40);
   SetMessages( ({
    ({ "", "A %^MAGENTA%^surging wall of energy %^RESET%^forms around $target_name." }),
    ({ "strike", "The %^MAGENTA%^energy wall %^RESET%^around $agent_name shimmers as $target_name $target_verb it." }),
    ({ "", "The %^RED%^wall of energy %^RESET%^around $agent_name disperses." }),
    }) );
   SetHelp(
    "This time based shield creates a wall of energy around the target which will "
    "block all external damage until the duration of the spell ends."
    );
 }
