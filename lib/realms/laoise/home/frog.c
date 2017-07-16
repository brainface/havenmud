#include <lib.h>
inherit LIB_NPC;

static void create(){
  npc::create();
  SetKeyName("bullfrog");
  SetId( ({"frog", "bullfrog"}) );
  SetAdjectives( ({"small", "green", "bull"}) );
  SetShort("a green bullfrog");
  SetLong(
    "Of a relatively large size for a frog, "
    "this bullfrog is still tiny compared to most "
    "living creatures. A dark green color across "
    "most of his body, this frog's head is a "
    "lighter green color across the top and "
    "white underneath his chin. His eyes stick "
    "up slightly from the top of his head, and "
    "he has two round patches in the skin just "
    "behind them. Due to his small size and timid "
    "manner, this frog does not seem to be a "
    "tough opponent."
  );
  SetRace("amphibian");
  SetClass("animal");
  SetLevel(1);
  SetGender("male");
  SetAction(10, ({
    "The green bullfrog ribbits.",
    "!hop"
  }) );
  SetCombatAction(10, ({
    "The green bullfrog tries to hop away.",
  }) );
}
