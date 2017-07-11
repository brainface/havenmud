#include <lib.h>
#include <domains.h>
inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("hustin");
  SetShort("Hustin the Quest Giver");
  SetId( ({ "giver", "hustin" }) );
  SetAdjectives( ({ "quest" }) );
  SetClass("merchant");
  SetLevel(10);
  SetRace("human");
  SetGender("female");
  SetBaseLanguage("Eltherian");
  SetTown("Haven");
  SetLong(
    "Hustin is a lovely woman in her mid-40s. Her striking black hair "
    "flows freely to her waist. Hustin has the enviable task of assigning "
    "quests to those in need of them. Those in need of a quest should <ask "
    "hustin for quests>."
    );
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(15, ({
    "!speak You could ask me for a quest.",
    "!speak You could request quests from me.",
  }) );
}


