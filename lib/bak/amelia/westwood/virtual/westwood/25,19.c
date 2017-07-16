#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "river_inheritable.c";

static void create(int x, int y) {
  ::create(25, 19);
  SetObviousExits("north, northwest, west, southwest, south");
  SetExits( ([
    "north" : V_ROOM + "25,20",
    "northwest" : V_ROOM + "24,20",
    "west" : V_ROOM + "24,19",
    "southwest" : V_ROOM + "24,18",
    "south" : V_ROOM + "25,18",
  ]) );
}
