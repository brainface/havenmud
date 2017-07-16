#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

int PreventLeaveParva();

static void create() {
  ::create();
  SetExits( ([
    "west" : PARVA_ROOM "path5",
    "east" : PARVA_ROOM "wharf1",
    ]) );
  SetShort("a small dirt road in Parva");
  SetLong(
    "The shabby dirt path that runs here from east to west near "
    "the smelly ocean shore stands between two long rows of "
    "broken-down buildings, which loom over the road with a "
    "decisively unsettling lean. One building seems to stand "
    "sturdily on its own, a house of healing, but otherwise this "
    "part of the town looks much like any other."
  );
  SetItems( ([
    ({ "road", "path" }) :
     "This dirt path serves as the main road in Parva.",
    ({ "building", "buildings" }) :
    "Most of the buildings in Parva are decrepit and very near to collapse. "
     "One building by the roadside however seems to be a house of healing "
     "and looks slightly less likely to collapse at any given moment.",
    ({ "ocean", "shore" }) : "The shore and the docks are to the east.",
    ({ "dock", "docks" }) : "The docks are farther off to the east.",                               
    ({ "house", "healing" }) :
     "The house of healing is a place to be restored to health and vitality.",
    ]) );
  SetItemAdjectives( ([
    "house" : ({ "house", "of", }),
    "path" : ({ "shabby", "dirt" }),
    "shore" : ({ "ocean", "smelly" }),
    ]) );
  SetEnters( ([
    "house" : PARVA_ROOM "healer",
    ]) );
  SetSmell("Something smells positively awful in this town.");
  SetListen("At all hours, Parva is alive with raucous noise.");
  SetInventory( ([
    ]) );
}
