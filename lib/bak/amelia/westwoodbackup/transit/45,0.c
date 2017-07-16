#include <lib.h>
inherit LIB_ROOM;

static void create(int x, int y) {
  ::create(45, 0);
  SetObviousExits("west");
  SetShort("a path leading though the mountains");
  SetClimate("sub-artic");
  SetLong("The road seems to come to an end here.  There are "
    "fallen trees about and it seems as though a path is being "
    "cleared to allow movement through here.");
  SetExits( ([
    "west" : "/domains/westwood/virtual/transit/44,0",
  ]) );
  SetInventory( ([
    "/domains/westwood/virtual/transit/gelfling" : 3,
    "/domains/westwood/virtual/transit/merc" : 5,
  ]) );
}
