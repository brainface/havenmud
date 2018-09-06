/* guardian geist
 * Mahkefel 2017--demigod damage based shield for faith necro
 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("guardian geist");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetShieldType(SHIELD_DAMAGE);
  SetSkills( ([
    "faith"      : 500,
    "necromancy" : 500,
    ]) );
  SetDifficulty(0);
  SetProtectionTypes(ALL_EXTERNAL);
  SetMessages(
    ({
      ({ "rouse", "$agent_name $agent_verb an %^CYAN%^ancient "
        "ephemeral guardian%^RESET%^ from the plane of the dead "
        "to defend $target_name." }),
      ({ "", "$agent_possessive_noun %^CYAN%^guardian geist%^RESET%^ "
        "blocks the blow with a %^BOLD%^WHITE%^spectral shield!%^RESET%^" }),
      ({ "", "$agent_possessive_noun %^CYAN%^guardian geist%^RESET%^ "
        "screams futily and %^BOLD%^BLACK%^dissolves%^RESET%^ into "
        "messy ectoplasm."}),
    }) );
  SetHelp(
  "The most blessed of priests can call upon the long-departed spirits of "
  "ancient warriors and heros to defend them."
    );
}

