#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

int PreventLeaveParva();

static void create() {
  ::create();
  SetExits( ([
    "east" : PARVA_ROOM "path2",
    ]) );
  AddExit("west", PARVA_ROAD, (: PreventLeaveParva :) );
  SetShort("a small dirt road into Parva");
  SetLong(
    "The city of Parva sprawls to the east. Parva is a wreckage of buildings "
    "that are in various states of disrepair, and the citizens of the city seem "
    "to have absolutely no regard or concern for this state of affairs. The main "
    "'road' is nothing more than a dirt path leading into town, and the only "
    "feature of note seems to be the docks far off to the east. There is a building "
    "here that seems to serve as a town hall."
  );
  SetItems( ([
    ({ "road", "path" }) : "This dirt path serves as the main road in Parva.",
    ({ "building", "buildings" }) : "Most of the buildings in Parva are decrepid and "
                                    "very near to collapse. One building by the road"
                                    "side however seems to serve as a town hall, and "
                                    "looks slightly less likely to collapse at any "
                                    "given moment.",
    ({ "dock", "docks" }) : "The docks are farther off to the east.",                               
    ({ "hall" }) : "The town hall seems less pathetic than most other buildings.",
    ]) );
  SetItemAdjectives( ([
    "road" : ({ "dirt" }),
    "hall" : ({ "town" }),
    ]) );
  SetEnters( ([
    "hall" : PARVA_ROOM "town_hall",
    ]) );
  SetSmell("Something smells positively awful in this town.");
  SetListen("At all hours, Parva is alive with raucous noise.");
  SetInventory( ([
      PARVA_NPC "acrobat" : 1,
    ]) );
}

int PreventLeaveParva() {
    if (this_player()->id("parva_wander")) {
      if (this_player()->GetOwner() == "")
        return 0;
      }
    if (this_player()->GetProperty("parvanoleave")) {
      if (this_player()->GetOwner() == "")
        return 0;
      }
  return 1;
}
