#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "lake_inheritable.c";

static void create(int x, int y) {
  ::create(22, 6);
  SetObviousExits("east, northeast, north, northwest, west, southwest, south");
  SetExits( ([
    "east" : V_ROOM + "23,6",
    "northeast" : V_ROOM + "23,7",
    "north" : V_ROOM + "22,7",
    "northwest" : V_ROOM + "21,7",
    "west" : V_ROOM + "21,6",
    "southwest" : V_ROOM + "21,5",
    "south" : V_ROOM + "22,5",
  ]) );
}
