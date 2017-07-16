
#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("butterfly");
  SetRace("insect");
  SetGender("male");
  SetShort("a bullying butterfly");
  SetId( ({ "butterfly", "bullyfly" }) );
  SetAdjectives( ({ "bullying" }) );
  SetLong(
    "Ah, the rare bullying butterfly, or bullyfly, if you will. "
    "Incongruously covered in muscles and bulging with hate. You can "
    "see the skulls there, decorating the wings, as opposed to the more "
    "mundane 'splotches' present on other butterfly wings. Their specific "
    "evolutionary traits are a bit of a mystery, but 'a bad home life' is "
    "one hypothesis that has grown traction in recent years."  );

  SetClass("horror");
  SetLevel(5);

  SetAction(15, ({
    "!emote steals your lunch money, then spirals to the floor under the weight of it!",
    "!emote gives you the tiniest indian sunburn!",
    "!emote flutters into your eye like a big jerk!",
    "!emote attempts to shove you, causing you to not much care due to things like inertia and momentum!",
    "!emote tries to look big, and fails!",
    "!emote lands on your forehead and ineffectively begins punching you gently with all six legs!",
  }) );
}

