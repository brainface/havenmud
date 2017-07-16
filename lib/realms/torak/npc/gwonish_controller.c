#include <lib.h>
#include <domains.h>
inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("Sstorvor");
  SetShort("Sstorvor");
  SetId( ({ "sstorvor" }) );
  SetClass("fighter");
  SetLevel(100);
  SetRace("lizardman");
  SetGender("male");
  SetBaseLanguage("Slith");
  SetTown("Gwonish");
  SetLong(
    "SStorvor is a spear maker for the lizardman of Gwonish. "
    "His green, scaly body shows many scars from glorious "
    "battle. "
    );
  }

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(15, ({
    "!speak You could ask me for a quest.",
    "!speak You could request quests from me.",
  }) );
}
