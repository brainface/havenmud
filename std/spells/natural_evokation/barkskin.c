/* balanced by Dylanthalus@Haven May 06th, 1999*/

#include <magic.h>
#include <lib.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("barkskin");
  SetRules("", "LIV");
  SetSkills( ([
   "natural magic" : 1,
   "evokation"     : 1,
  ]) );
  SetDifficulty(15); // 55
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_DAMAGE);
  SetHelp(
    "This natural magic spell causes the target's skin to be covered "
    "a layer of bark effectively protecting the target against "
    "damage from all physical based and magical attacks."
    );
  SetMessages( ({
    ({ "",  "A %^BOLD%^%^GREEN%^covering of wood%^RESET%^ appears around " +
        "$target_possessive_noun body." }),
    ({ "strike", "%^BOLD%^GREEN%^Splinters%^RESET%^ fly as $target_name "
                 "$target_verb $agent_name." }),
    ({ "",  "The barkskin around $agent_name %^ORANGE%^shatters%^RESET%^ into " +
            "nothingness." })
     }) );
}
