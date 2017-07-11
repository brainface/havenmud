#include <lib.h>
#include <domains.h>
inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("eralyon");
  SetShort("Eralyon the Quest Giver");
  SetId( ({ "giver", "eralyon" }) );
  SetAdjectives( ({ "quest" }) );
  SetRace("lamrani");
  SetGender("male");
  SetBaseLanguage("Sprith");
  SetTown("Jidoor");
  SetLong("Eralyon is an old, wise-looking lamrani. His grey skin, wrinkled by age, "
    "appears to sag. Known throughout Jidoor for his exemplary participation "
    "in various conflicts that the city has found itself involved in, he now spends "
    "what remaining time he has left on this world aiding the younger citizens, primarily "
    "by assigning them quests to further their knowledge of the world around them. Those "
    "in need of a quest should <ask eralyon for quests>."
  );
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(15, ({
    "!speak You could ask me for a quest.",
    "!speak You could request quests from me.",
  }) );
}

