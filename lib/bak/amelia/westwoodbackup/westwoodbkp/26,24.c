#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "river_inheritable.c";

static void create(int x, int y) {
  ::create(26, 24);
  SetObviousExits("north, northwest, west, southwest, south, northeast");
  SetExits( ([
    "north" : V_ROOM + "26,25",
    "northwest" : V_ROOM + "25,25",
    "west" : V_ROOM + "25,24",
    "southwest" : V_ROOM + "25,23",
    "south" : V_ROOM + "26,23",
    "northeast" : V_ROOM + "27,25",
  ]) );
}
