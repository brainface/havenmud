

//Selket@Haven
//2006
#include <lib.h>
#include "../lake.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("sheep");
  SetShort("a large fluffy sheep");
  SetId( ({ "sheep" }) );
  SetAdjectives( ({ "fluffy", "large" }) );
  SetRace("sheep");
  SetGender("male");
  SetClass("animal");
  SetLevel(8);
  SetLong("This sheep is enormous, but mostly fluffy wool. He "
          "seems to be very well cared for and doesn't try to "
          "stray far from his owners.");
  SetAction(10, ({
    "!emote prances a little.",
    "!bah",
    "!emote bends over and chews on the grass.",
    }) );
  SetCombatAction(20, ({
    "!bah",
  }) );
}
