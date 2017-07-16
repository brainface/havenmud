#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "lake_inheritable.c";

static void create(int x, int y) {
  ::create(24, 1);
  SetObviousExits("north, northwest, west, southwest, south");
  SetExits( ([
    "north" : V_ROOM + "24,2",
    "northwest" : V_ROOM + "23,2",
    "west" : V_ROOM + "23,1",
    "southwest" : V_ROOM + "23,0",
    "south" : V_ROOM + "24,0",
  ]) );
}
