#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "lake_inheritable.c";

static void create(int x, int y) {
  ::create(22, 4);
  SetObviousExits("north, northwest, west, southwest, south");
  SetExits( ([
    "north" : V_ROOM + "22,5",
    "northwest" : V_ROOM + "21,5",
    "west" : V_ROOM + "21,4",
    "southwest" : V_ROOM + "21,3",
    "south" : V_ROOM + "22,3",
  ]) );
}
