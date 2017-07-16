#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("iron");
  SetRace("golem","tool");
  SetGender("male");
  SetShort("a huge fucking soldering iron");
  SetId( ({ "iron" }) );
  SetAdjectives( ({ "huge", "fucking" }) );
  SetLong(
    "Huh. How about that?"
      );

  SetClass("animal");
  SetStat("strength", 100, 1);
  SetLevel(1);

  SetAction(1, ({
    "!emote solders, for it is a soldering iron.",
    /*
    "!emote jumps right at you!",
    "!emote crawls up your leg!",
    "!emote is caught in your hair!",
    "!emote does that thing where he like makes a balloon out of webbing and floats around. Weird.",
    "!emote makes this huge assed web across the doorway just like fucking spiders do.",
    "!emote crawls into your shoe to hide.",*/
    }) );
}

