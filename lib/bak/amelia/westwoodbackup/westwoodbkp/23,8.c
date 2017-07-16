#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "lake_inheritable.c";

static void create(int x, int y) {
  ::create(23, 8);
  SetObviousExits("northeast, north, northwest, west, southwest, south");
  SetExits( ([
    "northeast" : V_ROOM + "24,9",
    "north" : V_ROOM + "23,9",
    "northwest" : V_ROOM + "22,9",
    "west" : V_ROOM + "22,8",
    "southwest" : V_ROOM + "22,7",
    "south" : V_ROOM + "23,7",
  ]) );
}
