#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "lake_inheritable.c";

static void create(int x, int y) {
  ::create(22, 2);
  SetObviousExits("east, north, northwest, west, southwest, south, southeast");
  SetExits( ([
    "east" : V_ROOM + "23,2",
    "north" : V_ROOM + "22,3",
    "northwest" : V_ROOM + "21,3",
    "west" : V_ROOM + "21,2",
    "southwest" : V_ROOM + "21,1",
    "south" : V_ROOM + "22,1",
    "southeast" : V_ROOM + "23,1",
  ]) );
}
