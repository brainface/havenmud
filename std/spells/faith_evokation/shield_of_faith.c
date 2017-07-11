/* Shield of Faith
 * Balanced by Dylanthalus April 11, 99
 * SetDetailedHelp() by Ranquest
 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("shield of faith");
   SetRules("","LIV");
   SetSpellType(SPELL_DEFENSE);
   SetProtectionTypes(ALL_EXTERNAL);
   SetShieldType(SHIELD_TIMED);
   SetDifficulty(50);
   SetSkills( ([
     "faith" : 80,
     "evokation" : 80,
            ]) );
   SetMessages( ({
    ({ "", "A sparkling %^BLUE%^shield of faith%^RESET%^ shimmers "
           "into being around $target_name." }),
    ({ "", "A sparkling %^BLUE%^shield of faith%^RESET%^ around "
           "$agent_name seems to absorb some of the attack from "
           "$target_name." }),
    ({ "", "A sparkling %^RED%^shield of faith%^RESET%^ around "
           "$agent_name fades from view." }),
              }) );
  SetHelp(
           "Creates a physical shield of faith around the living "
           "target, or the caster if no target is given. The shield "
           "defends the target from all types of damage for the duration "
           "of the spell.");
}


/* Approved by Dylanthalus on Wed Dec  2 22:43:12 1998. */
