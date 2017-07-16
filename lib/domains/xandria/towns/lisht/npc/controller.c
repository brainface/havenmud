// mahkefel jan '11
#include <lib.h>
#include <domains.h>
#include <std.h>
#include "../lisht.h"
inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("Taramet");
  SetShort("Taramet, the Overseer");
  SetId( ({ "taramet","overseer" }) );
  SetAdjectives( ({ "taramet","the","overseer" }) );
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetClass("merchant");
    SetLevel(15); //ooolllddd
  SetGender("male");
  SetTown("Lisht");
  SetLong(
    "This hoary gnoll is bent and weathered with age. Once a great "
    "and respected scribe for the library, he can no longer see well "
    "enough to perform his duties, and the pharoah has tasked him with "
    "organizing the idle workers of Lisht to whatever greater purposes "
    "he can devise."
  );
  SetInventory( ([
    LISHT_OBJ "shenti" : "wear shenti",
    STD_POLE "staff" : "wield staff",
  ]) );
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(15, ({
    "!speak The walled city has many quests for an idle one such as you.",
    "!speak Citizen or slave, I care not, so long as you can "
      "complete a quest as given.",
    "!speak You could ask me for a quest.",
    "!speak You could request quests from me.",
  }) );
}

