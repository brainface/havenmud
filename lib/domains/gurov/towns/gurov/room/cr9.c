#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetExits( ([
    "south" : GUROV_ROOM "cr8",
    "north" : GUROV_ROOM "dock2",
    ]) );
  SetShort("the Center Road near the docks");
  SetLong(
    "The Center Road continues to the south from here. Directly to the "
    "north lie the Gurov Docks, which border on the bay and serve as "
    "a clear line between the sea and the land. Off to the south, the "
    "road meets up with the Prince's Road which heads off east. The "
    "main road continues off in the distance to the town gate."
    );
  SetItems( ([
    ({ "docks", "dock" }) : "The docks lie to the north.",
    ]) );
  SetSmell("The scent of the sea wafts in from the north.");
  SetListen("The gentle crash of waves comes from the north.");
}