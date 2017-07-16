#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "north" : PARVA_ROOM "path2",
    "south" : PARVA_ROOM "cemetery",
    ]) );
  SetShort("a small dirt road in Parva");
  SetLong(
    "The dusty path leads north and south through Parva here between two rows "
    "of equally rudely-constructed buildings. In the distance to the south, "
    "one can just make out the cemetery, and in the north stands a crossroads."
  );
  SetItems( ([
    ({ "road", "path" }) : "This dirt path serves as the main road in Parva.",
    ({ "building", "buildings" }) : "Most of the buildings in Parva are decrepit and "
                                    "very near to collapse.",                            
    ]) );
  SetItemAdjectives( ([
    "road" : ({ "dirt" }),
    ]) );
  SetEnters( ([
    ]) );
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
