#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "lake_inheritable.c";

static void create(int x, int y) {
  ::create(21, 5);
  SetObviousExits("east, northeast, north, northwest, west, southwest, south, southeast");
  SetExits( ([
    "east" : V_ROOM + "22,5",
    "northeast" : V_ROOM + "22,6",
    "north" : V_ROOM + "21,6",
    "northwest" : V_ROOM + "20,6",
    "west" : V_ROOM + "20,5",
    "southwest" : V_ROOM + "20,4",
    "south" : V_ROOM + "21,4",
    "southeast" : V_ROOM + "22,4",
  ]) );
}
