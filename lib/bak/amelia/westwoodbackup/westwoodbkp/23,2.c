#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "lake_inheritable.c";

static void create(int x, int y) {
  ::create(23, 2);
  SetObviousExits("northwest, west, southwest, south, southeast, east");
  SetExits( ([
    "northwest" : V_ROOM + "22,3",
    "west" : V_ROOM + "22,2",
    "southwest" : V_ROOM + "22,1",
    "south" : V_ROOM + "23,1",
    "southeast" : V_ROOM + "24,1",
    "east" : V_ROOM + "24,2",
  ]) );
}
