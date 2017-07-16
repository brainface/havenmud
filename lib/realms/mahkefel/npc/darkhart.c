#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("darkhart");
  SetRace("deer");
  SetGender("female");
  SetShort("a shaggy darkhart");
  SetId( ({ "darkhart", "hart" }) );
  SetAdjectives( ({ "shaggy", "dark" }) );
  SetLong(
    "This creature is a darkhart, an unusually large deer found in "
    "the forests of havenwood, and contrasted from its more common "
    "cousin by its bulk and bitter disposition. Its ebony fur is marked "
    "by a whirling crimson pattern, and long jagged antlers sit atop "
    "a narrow head, from which beady red eyes glare out at you. "
  );
  SetClass("animal");
  SetAction(5, 
    ({"!emote stomps her hoofs agitatedly.",
      "!emote clicks warningly.",
      "!emote bleats dangerously.",
      "!emote lowers her head, pointing a dozen sharp antler points at you.",
      "!emote prances around fearsomely.",
    }) );
  //SetStat("strength", 100, 1);
  SetLevel(20);
}

