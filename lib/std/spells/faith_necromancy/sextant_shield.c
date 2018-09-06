/* sextant's shield
 * Mahkefel 2017--mortal damage based shield for faith necro
 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("sextant's shield");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetShieldType(SHIELD_DAMAGE);
  SetSkills( ([
    "faith"      : 50,
    "necromancy" : 50,
    ]) );
  SetDifficulty(0);
  SetProtectionTypes(ALL_EXTERNAL);
  SetMessages(
    ({
      ({ "call", "$agent_name $agent_verb forth a tumbling whirlwind of "
        "%^YELLOW%^shattered caskets, %^BLACK%^BOLD%^broken headstones, and "
        "%^BOLD%^WHITE%^wrought iron%^RESET%^ to surround $target_name."}),
      ({ "", "$agent_possessive_noun %^YELLOW%^deathly debris%^RESET%^ "
        "absorbs the attack!"}),
      ({ "", "The %^YELLOW%^graveyard debris surrounding $agent_name "
        "shatters into a useless cloud of%^YELLOW%^ loam%^RESET%^ and "
        "%^BOLD%^BLACK%^gravedust%^RESET%^!"}),
    }) );
  SetHelp(
    "A practiced death priest can summon forth debris from forgotten "
    "cemeteries and lost graveyards to cover and protect them."
    );
}

