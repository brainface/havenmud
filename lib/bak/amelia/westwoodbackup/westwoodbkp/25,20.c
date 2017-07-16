#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "river_inheritable.c";

static void create(int x, int y) {
  ::create(25, 20);
  SetObviousExits("northeast, north, northwest, west, southwest, south");
  SetExits( ([
    "northeast" : V_ROOM + "26,21",
    "north" : V_ROOM + "25,21",
    "northwest" : V_ROOM + "24,21",
    "west" : V_ROOM + "24,20",
    "southwest" : V_ROOM + "24,19",
    "south" : V_ROOM + "25,19",
  ]) );
}
