/* Aegis of the Faithful
 * Thoin@haven
 * 01-08-01
 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("aegis of the faithful");
   SetRules("","LIV");
   SetSpellType(SPELL_DEFENSE);
   SetProtectionTypes(ALL_EXTERNAL);
   SetShieldType(SHIELD_TIMED);
   SetDifficulty(50);
   SetSkills( ([
     "faith" : 50,
     "evokation" : 50,
            ]) );
   SetMessages( ({
    ({ "", "Brilliant dancing %^BOLD%^%^WHITE%^lights%^RESET%^ flitter "
           "around $target_name forming a shield." }),
    ({ "", "The dancing %^BOLD%^%^WHITE%^lights%^RESET%^ around "
           "$agent_name seem to absorb the attack from "
           "$target_name." }),
    ({ "", "The dancing %^CYAN%^lights%^RESET%^ around "
           "$agent_name fade from existence." }),
              }) );
  SetHelp(
           "Creates a shield of magical lights around the living "
           "target, or the caster if no target is given that protects them "
           "from all damage for the duration of the shield.");
}
