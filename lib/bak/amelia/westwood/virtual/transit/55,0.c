#include <lib.h>
inherit LIB_ROOM;

static void create(int x, int y) {
  ::create(55, 0);
  SetObviousExits("east");
  SetShort("a path leading though the mountains");
  SetClimate("temperate");
  SetLong("The road seems to come to an end here.  There are "
    "fallen trees about and it seems as though a path is being "
    "cleared to allow movement through here.");
  SetExits( ([
    "east" : "/domains/westwood/virtual/transit/56,0",
  ]) );
  SetInventory( ([
    "/domains/westwood/virtual/transit/gelfling" : 3,
  ]) );
}
