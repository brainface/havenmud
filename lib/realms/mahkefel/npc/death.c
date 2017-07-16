#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("spider");
  SetRace("arachnid");
  SetGender("female");
  SetShort("Spider Death (afk)");
  SetId( ({ "spider","death", }) );
  SetAdjectives( ({ "spider" }) );
  SetLong(
    "This terrible eight legged arachnide is made of hate "
    "and crushed dreams. And lazyness. Sloths look at this "
    "thing and get bored. You think it'll be a terrible "
    "monsterous threat, whenever, you know, it feels like "
    "it, mom."
  );

  SetClass("cavalier");
  SetLevel(10);

  SetAction(5, ({
    "!emote yawns, somehow.",
    "!emote waves a leg at you noncommitedly",
    "!emote eyes you with ancient and hungry eyes. Oh, wait, it's asleep.",
    "!emote sighs dejectedly.",
    "!emote makes a gesture that you think signifies it would really like for you to sort of just stick your head in its mandibles so it wouldn't have to bother.",
  }) );
}

