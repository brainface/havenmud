#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

int PreventLeaveParva();

static void create() {
  ::create();
  SetExits( ([
    "east" : PARVA_ROOM "path5",
    ]) );
  SetShort("a small dirt road into Parva");
  SetLong(
    "The dirt road dead ends here in front of the HavenWood. "
    "Just before the treeline, a tall, sprawling building with a "
    "cleanly swept entrance stands. It appears to be a hospital. "
    "The road leads back towards the eastern shore, through "
    "the rest of the city."
  );
  SetItems( ([
    ({ "road", "path" }) : "This dirt path serves as the main road in Parva.",
    ({ "building", "buildings" }) : "Most of the buildings in Parva are decrepid and "
                                    "very near to collapse. One building by the road"
                                    "side however seems to serve as a hospital, and "
                                    "looks slightly less likely to collapse at any "
                                    "given moment.",
    ({ "dock", "docks" }) : "The docks are farther off to the east.",                               
    ({ "hospital"}) : "The hospital seems less pathetic than most other buildings.",
    ({ "treeline", "wood", "havenwood" }) :
    "The thick treeline of the HavenWood blocks all passage west.",
    ({ "entrance" }) :
    "The entrance is swept clean of debris to keep diseases out.",
    ]) );
  SetItemAdjectives( ([
    "road" : ({ "dirt" }),
    "hospital" : ({ "tall", "sprawling" }),
    "entrance" : ({ "cleanly", "swept" }),
    ]) );
  SetEnters( ([
    ]) );
  AddEnter("hospital", HAVENWOOD_AREAS "parvahosp/room/entrance", (: PreventLeaveParva :) );
  SetSmell("Something smells positively awful in this town.");
  SetListen("At all hours, Parva is alive with raucous noise.");
  SetInventory( ([
    PARVA_NPC "cit_steal" : 3,
    ]) );
}

int PreventLeaveParva() {
    if (this_player()->id("parva_wander")) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
}
