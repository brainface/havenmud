
#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("creepy kid");
  SetRace("human");
  SetGender("male");
  SetShort("a creepy kid");
  SetId( ({ "kid" }) );
  SetAdjectives( ({ "creepy" }) );
  SetLong(
    "This child, five or six years old, gazes forward with "
    "soul-dead eyes. He has something to give you. It's "
    "very important."
  );

  SetClass("rogue");
  SetLevel(1);
  SetInventory( ([
    "/realms/mahkefel/obj/spiderjar" : random(10),
  ]) );

  SetAction(15, ({
    /*"!say I made this for you mother.",
    "!give first jar to alessandra",
    "!emote grins proudly.",
    "!emote gazes forward blankly.",*/
    "!say Do you like bologna?",
    "!say I want to poop back and forth.",
    "!say FOREVER!",
    "!say And then we'll just keep doing it, with the same poop.",
  }) );
}

