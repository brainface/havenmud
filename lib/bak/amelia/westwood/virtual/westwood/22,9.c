#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "lake_inheritable.c";

static void create(int x, int y) {
  ::create(22, 9);
  SetObviousExits("east, northeast, north, northwest, west, southwest, south, southeast");
  SetExits( ([
    "east" : V_ROOM + "23,9",
    "northeast" : V_ROOM + "23,10",
    "north" : V_ROOM + "22,10",
    "northwest" : V_ROOM + "21,10",
    "west" : V_ROOM + "21,9",
    "southwest" : V_ROOM + "21,8",
    "south" : V_ROOM + "22,8",
    "southeast" : V_ROOM + "23,8",
  ]) );
}
