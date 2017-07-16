#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "river_inheritable.c";

static void create(int x, int y) {
  ::create(24, 10);
  SetObviousExits("north, northwest, west, southwest, south");
  SetExits( ([
    "north" : V_ROOM + "24,11",
    "northwest" : V_ROOM + "23,11",
    "west" : V_ROOM + "23,10",
    "southwest" : V_ROOM + "23,9",
    "south" : V_ROOM + "24,9",
  ]) );
}
