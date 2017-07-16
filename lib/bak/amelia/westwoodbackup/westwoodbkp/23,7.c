#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "lake_inheritable.c";

static void create(int x, int y) {
  ::create(23, 7);
  SetObviousExits("north, northwest, west, southwest, south");
  SetExits( ([
    "north" : V_ROOM + "23,8",
    "northwest" : V_ROOM + "22,8",
    "west" : V_ROOM + "22,7",
    "southwest" : V_ROOM + "22,6",
    "south" : V_ROOM + "23,6",
  ]) );
}
