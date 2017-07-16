#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "river_inheritable.c";

static void create(int x, int y) {
  ::create(26, 21);
  SetObviousExits("northeast, north, northwest, west, southwest");
  SetExits( ([
    "northeast" : V_ROOM + "27,22",
    "north" : V_ROOM + "26,22",
    "northwest" : V_ROOM + "25,22",
    "west" : V_ROOM + "25,21",
    "southwest" : V_ROOM + "25,20",
  ]) );
}
