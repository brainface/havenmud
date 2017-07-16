#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "lake_inheritable.c";

static void create(int x, int y) {
  ::create(22, 3);
  SetObviousExits("north, northwest, west, southwest, south, southeast");
  SetExits( ([
    "north" : V_ROOM + "22,4",
    "northwest" : V_ROOM + "21,4",
    "west" : V_ROOM + "21,3",
    "southwest" : V_ROOM + "21,2",
    "south" : V_ROOM + "22,2",
    "southeast" : V_ROOM + "23,2",
  ]) );
}
