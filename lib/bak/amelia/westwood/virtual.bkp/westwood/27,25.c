#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "river_inheritable.c";

static void create(int x, int y) {
  ::create(27, 25);
  SetObviousExits("north, northwest, west, southwest");
  SetExits( ([
    "north" : V_ROOM + "27,26",
    "northwest" : V_ROOM + "26,26",
    "west" : V_ROOM + "26,25",
    "southwest" : V_ROOM + "26,24",
  ]) );
}
