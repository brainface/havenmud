#include <lib.h>
#include "../path.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("sheep");
  SetShort("a fluffy white sheep");
  SetId( ({ "sheep" }) );
  SetAdjectives( ({ "fluffy", "white" }) );
  SetRace("sheep");
  SetGender("female");
  SetClass("animal");
  SetLevel(2);
  SetLong("This sheep is of the normal, non-magical variety. "
          "While it could be useful to make a wool coat or "
          "woolen mittens out of, for now it remains a sheep.");
  SetAction(10, ({
    "!emote bleats.",
    "!bah",
    "!emote stares around the room with a bored, unconcerned look.",
    "!emote bends over and chews on the grass.",
    }) );
  SetCombatAction(20, ({
    "!whimper",
  }) );
  SetMorality(20);
}

  
