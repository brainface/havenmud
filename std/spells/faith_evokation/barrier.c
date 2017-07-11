/*  BARRIER v 2.0 for Haven
 *  Coded by Malak@Haven
 *      modified for new spell system by Balishae 03/11/98
 *       rebalanced by Dylanthalus April 11/1999
 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("barrier of faith");
  SetRules("","LIV");
  SetSpellType(SPELL_DEFENSE);
  SetSkills( ([
        "faith"     : 100,
        "evokation" : 100,
        ]) );
  SetDifficulty(100);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED);
  SetMessages( ({
    ({"appear","$target_name $target_verb protected by "
                "%^BLUE%^BOLD%^holy energies%^RESET%^."}),
    ({"","The %^BLUE%^%^BOLD%^barrier of faith %^RESET%^defending"
                " $agent_name responds to the attacks of $target_name."}),
    ({"","The %^RED%^barrier of faith %^RESET%^around $agent_name collapses."})
    }) );
  SetHelp(
       "This spell of is one of the advanced cleric's most powerful "
       "all-round defenses. It protects the target from all types of attacks "
       "for the duration of the spell.");
}
