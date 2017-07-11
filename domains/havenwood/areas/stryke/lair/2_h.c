/*  Part of the tunnel */
#include <lib.h>
#include <daemons.h>
#include "../stryke.h"
inherit LIB_ROOM;
inherit LIB_TOUCH;

static void create() {
  room::create();
  SetClimate("indoors");
  SetLong("The tunnel opens up here into a large cavern entrance. "
          "To the east there is some kind of large cave which could "
          "be a lair to a large creature, while back to the southwest "
          "the tunnel leads toward the surface.");
  SetShort("a section of tunnel");
 SetObviousExits("southwest, east");
  SetExits( ([
    "east" : STRYKE_LAIR + "2_i",
    "southwest" : STRYKE_LAIR + "2_g",
   ]) );
  SetTouch( ([
    "default" : "You feel the heat of impending death upon you.",
  ]) );
}

int CanReceive(object ob) {
	if (userp(ob)) {
		CHAT_D->eventSendChannel("Stryke", "reports", this_player()->GetKeyName() +
            " is near my lair.");
    }
  return room::CanReceive(ob);
}
