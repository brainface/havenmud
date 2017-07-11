// mahkefel

#include <magic.h>
#include <lib.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("fortress of solitude");
  SetRules("", "LIV");
  SetSkills( ([
   "necromancy" : 500,
   "conjuring"  : 500,
  ]) );
  SetDifficulty(15); // 55
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_DAMAGE);
  SetHelp(
    "The oldest of liches can call to dead and dying things "
    "in the northern glaciers, surrounding themselves with an "
    "aegis of glacial ice from that realm, inuring them from "
    "all but the most determined assaults."
    );
  SetMessages( ({
    ({ "",  "A massive shell of %^BOLD%^WHITE%^glacial ice%^RESET%^ rises "
       "around $agent_name."}),
    ({ "assault", "A spray of ice %^BOLD%^CYAN%^shower%^RESET%^ the "
      "air as $target_name $target_verb $agent_name." }),
    ({ "",  "The glacial fortress around $agent_name " 
      "%^BOLD%^YELLOW%^crashes%^RESET%^ to the ground!" })
     }) );
}

