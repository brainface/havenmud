// mahkefel

#include <magic.h>
#include <lib.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("wall of iron");
  SetRules("", "LIV");
  SetSkills( ([
   "natural magic" : 350,
   "evokation"     : 350,
  ]) );
  SetDifficulty(15); // 55
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_DAMAGE);
  SetHelp(
    "A very skilled druid of avatar of nature can bend even iron "
    "to the will of the wild, forming it into protective bands "
    "around them, without impeding their abilities."
    );
  SetMessages( ({
    ({ "",  "A twirling %^BOLD%^BLACK%^ring of slag and iron%^RESET%^ swirls "
       "protectively around $agent_name."}),
    ({ "strike", "%^BOLD%^YELLOW%^Sparks%^RESET%^ fly as $target_name "
                 "$target_verb $agent_name." }),
    ({ "",  "The wall of iron around $agent_name %^RED%^rusts%^RESET%^ away!" })
     }) );
}

