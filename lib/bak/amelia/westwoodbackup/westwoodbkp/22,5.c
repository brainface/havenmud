#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "lake_inheritable.c";

static void create(int x, int y) {
  ::create(22, 5);
  SetObviousExits("northeast, north, northwest, west, southwest, south");
  SetExits( ([
    "northeast" : V_ROOM + "23,6",
    "north" : V_ROOM + "22,6",
    "northwest" : V_ROOM + "21,6",
    "west" : V_ROOM + "21,5",
    "southwest" : V_ROOM + "21,4",
    "south" : V_ROOM + "22,4",
  ]) );
}
