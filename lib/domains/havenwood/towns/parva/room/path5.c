
#include <lib.h>
#include <domains.h>
#include "../parva.h"
inherit LIB_ROOM;

int PreventLeaveParva();

static void create() {
  ::create();
  SetExits( ([
    "east" : PARVA_ROOM "path4",
    "west" : PARVA_ROOM "path6",
    ]) );
  SetShort("a small dirt road in Parva");
  SetLong(
    "Here the Parvan road slips between two rows of collapsing "
    "buildings from the ocean in the east to the western edge of the "
    "city, trailing into the HavenWood. The soil here is always "
    "dampened from the constant steam that issues out of one of "
    "one of the larger buildings, a bathhouse. To the south"
    " a small and broken down stable sits."
  );
  SetItems( ([
    ({ "road", "path" }) : "This dirt path serves as the main road in Parva.",
    ({ "building", "buildings" }) : "Most of the buildings in Parva are decrepid and "
                                    "very near to collapse. One building by the road"
                                    "side however seems to serve as a bathhouse, and "
                                    "looks slightly less likely to collapse at any "
                                    "given moment.",
    "steam" : "A thick cloud of steam comes from within the bathhouse.",
    ({ "dock", "docks" }) : "The docks are farther off to the east.",                               
    "soil" : "The soil is moist, heavy with humidity.",
    ({ "bathhouse" }) : "The bathhouse seems less pathetic than most other buildings.",
    ({ "stable" }) : "The stable looks worn and battered as if it has not been"
                     " taken care of for quite some time now.",
    ]) );
  SetItemAdjectives( ([
    "road" : ({ "dirt", "parvan" }),
    "bathhouse" : ({ "parva" }),
    ]) );
  SetEnters( ([
    "stable" : PARVA_ROOM "stable",
    ]) );   
  AddEnter("bathhouse", HAVENWOOD_AREAS "bathhouse/room/entrance", (: PreventLeaveParva :) );
//  AddEnter("stable", PARVA_ROOM "stable", (: PreventLeaveParva :) );
  SetSmell("Something smells positively awful in this town.");
  SetListen("At all hours, Parva is alive with raucous noise.");
  SetInventory( ([
    ]) );
}

int PreventLeaveParva() {
    if (this_player()->id("parva_wander")) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
}
