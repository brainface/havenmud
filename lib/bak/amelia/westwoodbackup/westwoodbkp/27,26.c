#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "river_inheritable.c";

static void create(int x, int y) {
  ::create(27, 26);
  SetObviousExits("north, northwest, west, southwest, south");
  SetExits( ([
    "north" : V_ROOM + "27,27",
    "northwest" : V_ROOM + "26,27",
    "west" : V_ROOM + "26,26",
    "southwest" : V_ROOM + "26,25",
    "south" : V_ROOM + "27,25",
  ]) );
}
