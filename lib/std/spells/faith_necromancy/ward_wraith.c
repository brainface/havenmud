/* wraith ward
 * Mahkefel 2017--mortal damage based shield for faith necro
 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("wraith ward");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetShieldType(SHIELD_DAMAGE);
  SetSkills( ([
    "faith"      : 200,
    "necromancy" : 200,
    ]) );
  SetDifficulty(0);
  SetProtectionTypes(ALL_EXTERNAL);
  SetMessages(
    ({
      ({ "pull", "$agent_name $agent_verb a %^BOLD%^CYAN%^whirling "
        "gyre%^RESET%^ of %^BOLD%^%WHITE%^wailing wraiths "
        "around $target_name!"}),
      ({ "", "Bits of %^BOLD%^CYAN%^ectoplasm%^RESET%^ fly off as "
        "$agent_possessive_noun %^BOLD%^WHITE%^warding wraiths%^RESET%^ "
        "intercept the blow!"}),
      ({ "", "The %^BOLD%^WHITE%^warding wraiths%^CYAN%^ whirling%^RESET%^ "
        "around $agent_name %^BOLD%^YELLOW%^gurgle angrily%^RESET%^ and "
        "disperse into a messy goo!"}),
    }) );
  SetHelp(
    "A powerful priest of death can summon spirits of the angry dead to ward "
    "her from violence until such creatures are dispersed."
  );
}

