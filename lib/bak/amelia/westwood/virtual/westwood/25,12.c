#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "river_inheritable.c";

static void create(int x, int y) {
  ::create(25, 12);
  SetObviousExits("northeast, north, northwest, west, southwest");
  SetExits( ([
    "northeast" : V_ROOM + "26,13",
    "north" : V_ROOM + "25,13",
    "northwest" : V_ROOM + "24,13",
    "west" : V_ROOM + "24,12",
    "southwest" : V_ROOM + "24,11",
  ]) );
}
