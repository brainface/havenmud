#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("raccoon");
  SetRace("rodent","raccoon");
  SetGender("female");
  SetShort("a scampering raccoon");
  SetId( ({ "scampering" }) );
  SetAdjectives( ({ "scampering" }) );
  SetLong(
    "This small and slightly pudgy raccoon seems on a mission. What that "
    "mission is seems to be over there, somewhere. Not where it's standing, "
    "wherever it's standing at the moment."
  );

  SetClass("rogue");
  SetLevel(1);

  SetAction(10, ({
    "!emote swivelfluffs in your direction.",
    "!emote magic bands!",
    "!emote boops you curiously.",
    "!emote scurries all over everything.",
    "!emote climbs up the wall.",
    "!emote rolly-pollies around you.",
    "!emote makes greedy grabbing motions at what you're holding.",
  }) );
}

