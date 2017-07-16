#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "lake_inheritable.c";

static void create(int x, int y) {
  ::create(21, 6);
  SetObviousExits("east, northeast, north, northwest, west, southwest, south, southeast");
  SetExits( ([
    "east" : V_ROOM + "22,6",
    "northeast" : V_ROOM + "22,7",
    "north" : V_ROOM + "21,7",
    "northwest" : V_ROOM + "20,7",
    "west" : V_ROOM + "20,6",
    "southwest" : V_ROOM + "20,5",
    "south" : V_ROOM + "21,5",
    "southeast" : V_ROOM + "22,5",
  ]) );
}
