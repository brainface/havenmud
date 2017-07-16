#include <lib.h>
#include "../westwood.h"
inherit LIB_ROOM;

static void create(int x, int y) {
  ::create(50, 0);
  SetShort("a path leading though the mountains");
  SetLong("This appears to be a road that cuts through a pass "
    "in the mountains of the Frostmarches.  It is mostly used "
    "used to transport goods and as a means of a shortcut "
    "across Kailie.  It looks to be travelled very little "
    "and is nothing more than a small path cutting though "
    "a valley in the mountains.  The road here intercepts with "
    "the road leading to Durgoroth to the west and the "
    "WestWood to the east.");
  SetClimate("temperate");
  SetSmell( ([
    "default" : "The light scent of fenfir trees seems to waft about."
  ]) );
  SetListen( ([
    "default" : "The wind howls through the pass here.",
  ]) );
  SetObviousExits("west, east, north");
  SetExits( ([
    "east" : "/domains/westwood/virtual/transit/51,0",
    "west" : "/domains/westwood/virtual/transit/49,0",
    "north" : "/domains/westwood/towns/fenfir/room/link",
  ]) );
}
