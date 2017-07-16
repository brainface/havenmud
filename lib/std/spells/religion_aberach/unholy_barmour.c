#include <magic.h>
#include <lib.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("unholy bone armour");
  SetRules("", "LIV");
  SetSkills( ([
   "faith" : 150,
   "necromancy" : 150,
  ]) );
  SetDifficulty(25);
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_DAMAGE);
  SetReligions( ({ "Aberach" }) );
  SetMaximumMorality(-500);
  SetHelp(
    "This necromantic spell allows the cleric to cover themselves "
    "in a layer of bones infused with magic that will protect them "
    "from a large amount of all physical and magical damage."
    );
  SetMessages( ({
    ({ "",  "A layer of %^BOLD%^%^RED%^bones%^RESET%^ wraps itself around " +
        "$target_possessive_noun body." }),
    ({ "", "Bone %^BOLD%^RED%^splinters%^RESET%^ fly at $target_name as $target_name "
                 "strike $agent_name." }),
    ({ "",  "The bones around $agent_name %^BLUE%^shatter%^RESET%^ into " +
            "nothingness." })
     }) );
}
