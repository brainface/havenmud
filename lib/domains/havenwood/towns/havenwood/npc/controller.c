#include <lib.h>
#include <domains.h>
#include <std.h>
inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("tyvalt");
  SetShort("Tyvalt the Mischief Maker and Quest Giver");
  SetId( ({ "giver", "tyvalt" }) );
  SetAdjectives( ({ "mischievous" }) );
  SetRace("wild-elf");
  SetGender("male");
  SetTown("Havenwood");
  SetClass("nightreveller");
  SetLevel(15);
  SetLong(
    "Tyvalt is a jolly looking young wild-elf who is known"
    " throughout the town as a mischief maker. His exploits"
    " are legendary among the town youth who look up to him"
    " and adore him as their leader. If someone were looking"
    " something to do they could <ask tyvalt"
    " for quests> . But only if they were willing to be"
    " a little wily.");
   SetAction(15, ({
    "!speak You could ask me for a quest.",
    "!sing tavernsong",
  "!sing solar ballad",
  "!sing lunar ballad",
    "!speak You could request quests from me.",
    "!snicker",
    "!speak Perhaps you should give Laurana a hug?"
     " She certainly looks like she could use one, heh heh",
  }) );

  SetInventory( ([
    STD_INSTRUMENTS "fife" : "wield fife",
  ]) );
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(15, ({
    "!speak You could ask me for a quest.",
    "!speak You could request quests from me.",
  }) );
}
