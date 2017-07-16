#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "river_inheritable.c";

static void create(int x, int y) {
  ::create(24, 16);
  SetObviousExits("north, northwest, west, southwest, south, southeast");
  SetExits( ([
    "north" : V_ROOM + "24,17",
    "northwest" : V_ROOM + "23,17",
    "west" : V_ROOM + "23,16",
    "southwest" : V_ROOM + "23,15",
    "south" : V_ROOM + "24,15",
    "southeast" : V_ROOM + "25,15"
  ]) );
}
