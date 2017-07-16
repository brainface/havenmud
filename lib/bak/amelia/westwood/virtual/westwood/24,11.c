#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "river_inheritable.c";

static void create(int x, int y) {
  ::create(24, 11);
  SetObviousExits("northeast, north, northwest, west, southwest, south");
  SetExits( ([
    "northeast" : V_ROOM + "25,12",
    "north" : V_ROOM + "24,12",
    "northwest" : V_ROOM + "23,12",
    "west" : V_ROOM + "23,11",
    "southwest" : V_ROOM + "23,10",
    "south" : V_ROOM + "24,10",
  ]) );
}
