#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "lake_inheritable.c";

static void create(int x, int y) {
  ::create(22, 8);
  SetObviousExits("east, northeast, north, northwest, west, southwest, south, southeast");
  SetExits( ([
    "east" : V_ROOM + "23,8",
    "northeast" : V_ROOM + "23,9",
    "north" : V_ROOM + "22,9",
    "northwest" : V_ROOM + "21,9",
    "west" : V_ROOM + "21,8",
    "southwest" : V_ROOM + "21,7",
    "south" : V_ROOM + "22,7",
    "southeast" : V_ROOM + "23,7",
  ]) );
}
