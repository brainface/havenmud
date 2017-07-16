#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "river_inheritable.c";

static void create(int x, int y) {
  ::create(24, 17);
  SetObviousExits("northeast, north, northwest, west, southwest, south");
  SetExits( ([
    "northeast" : V_ROOM + "25,18",
    "north" : V_ROOM + "24,18",
    "northwest" : V_ROOM + "23,18",
    "west" : V_ROOM + "23,17",
    "southwest" : V_ROOM + "23,16",
    "south" : V_ROOM + "24,16",
  ]) );
}
