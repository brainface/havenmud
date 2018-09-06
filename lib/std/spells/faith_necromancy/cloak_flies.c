/* Mahkefel 2017
 * lowbie damage shield for faith necro
 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("cloak of flies");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetShieldType(SHIELD_DAMAGE);
  SetSkills( ([
    "faith"      : 5,
    "necromancy" : 5,
    ]) );
  SetDifficulty(0);
  SetProtectionTypes(ALL_EXTERNAL);
  SetMessages(
    ({
      ({ "call", "$agent_name $agent_verb forth a %^BOLD%^BLACK%^swarm of flies%^RESET%^ to cloak and protect $agent_objective." }),
      ({ "", "$agent_possessive_noun %^BOLD%^BLACK%^cloak of flies%^RESET%^ buzz angrily against $target_possessive_noun attack!" }),
      ({ "", "The flies %^BOLD%^BLACK%^buzzing%^RESET%^ around $agent_name %^RED%^die messily%^RESET%^."}),
    }) );                 
  SetHelp(
    "Using his patron's power over death and decay, a novice priest can "
    "summon a swarm of the divine's least servants to intercede and protect "
    "them from harm."
    );
}

