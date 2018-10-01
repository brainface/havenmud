// Test mayor to run quests we assign
// this is for testing purposes. Urien 103113
#include <lib.h>
#include <domains.h>

inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("cultist");
  SetShort("a hooded cultist");
  SetId( ({ "cultist" }) );
  SetAdjectives( ({ "hooded" }) );
  SetClass("merchant");
  SetLevel(40);
  SetRace("human");
  SetGender("female");
  SetBaseLanguage("Eltherian");
  SetTown("TestTown");
  SetLong(
    "This particular cultist gives out quests to test chars. "
    "She is wearing a hooded cloak which is secured against "
    "her torso with a leather belt. She looks confident "
    "in her job issuing blood contracts and seizure notes "
    "from immortal contractors."
    );
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(15, ({
    "!speak Speak. Let the Dark Order guide your hand.",
    "!speak You can ask me for quests, child of darkness.",
  }) );
}


