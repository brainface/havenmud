//Illura@Haven
//May 2009
#include <lib.h>
#include <domains.h>
inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("Volodya");
  SetShort("Volodya the Quest Assignment Authority");
  SetId( ({"authority", "volodya" }) );
  SetAdjectives( ({ "quest", "assignment" }) );
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Gurovian");
  SetTown("Gurov");
  SetLong(
    "Volodya is a bearded man of middle age with twinkling brown "
    "eyes. He has the enviable task of assigning quests to those "
    "in need of them. Those in need of a quest should <ask "
    "volodya for quests>."
    );
}
void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(15, ({
    "!speak You could ask me for a quest, comrade.",
    "!speak Do your duty to the prince and ask me for a quest.",
  }) );
}
