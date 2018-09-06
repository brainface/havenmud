/* carrion cowl
 * Mahkefel 2017--mortal damage based shield for faith necro
 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("carrion cowl");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetShieldType(SHIELD_DAMAGE);
  SetSkills( ([
    "faith"      : 25,
    "necromancy" : 25,
    ]) );
  SetDifficulty(0);
  SetProtectionTypes(ALL_EXTERNAL);
  SetMessages(
    ({
      ({ "summon", "$agent_name $agent_verb a %^BOLD%^BLACK%^murder of crows%^RESET%^ to surround and shield $agent_objective." }),
      ({ "", "$agent_possessive_noun %^BOLD%^BLACK%^murder of crows%^RESET%^ swarm against $target_possessive_noun attack!" }),
      ({ "", "The crows %^BOLD%^BLACK%^flapping%^RESET%^ around $agent_name %^BOLD%^YELLOW%^caw%^RESET%^ one last time and die."}),
    }) );
  SetHelp(
    "With this spell an apprentice calls upon fowl creatures of carrion to "
    "surround and intercept attacks for them."
    );
}

