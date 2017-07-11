#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("watery touch");
  SetSpellType(SPELL_HEALING);
  SetSkills( ([
    "healing" : 3,
    "faith"   : 3,
    ]) );
  SetRules("", "LIV");
  SetAutoHeal(1);
  SetHealing(15, 15);
  SetMorality(1);
  SetMagicCost(15, 15);
  SetDifficulty(10);
  SetReligions("Damhair");
  SetHelp("This light healing spell is for use by Damhair clerics."
          "It is not highly effective.");
  SetMessages( ({
    ({ "drip", 
          "$agent_name $agent_verb a %^BLUE%^small amount of water%^RESET%^ on "
          "$target_name." }),
    ({ "touch",
          "$agent_name $agent_verb $target_name with a light, wet %^BLUE%^touch%^RESET%^."
          }),
    ({ "touch",
          "$agent_name%^BLUE%^ $agent_verb%^RESET%^ $target_name with "
          "$agent_possessive watery healing!",
          }),
     }) );
}
