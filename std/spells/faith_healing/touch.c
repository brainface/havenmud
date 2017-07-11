#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("touch");
  SetSpellType(SPELL_HEALING);
  SetSkills( ([
    "healing" : 1,
    "faith"   : 1,
    ]) );
  SetRules("", "LIV");
  SetMorality(1);
  SetDifficulty(10);
  SetAutoHeal(1);
  SetHelp("This is the first healing spell taught to all new clerics. "
          "It is not highly effective.");
  SetMessages( ({
    ({ "effect", 
          "$agent_name $agent_verb a %^BLUE%^small healing%^RESET%^ for "
          "$target_name." }),
    ({ "touch",
          "$agent_name $agent_verb $target_name with a light %^BLUE%^touch%^RESET%^."
          }),
    ({ "touch",
          "$agent_name%^BLUE%^ $agent_verb%^RESET%^ $target_name with "
          "$agent_possessive magic!",
          }),
     }) );
}
