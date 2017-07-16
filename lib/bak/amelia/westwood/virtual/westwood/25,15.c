#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "river_inheritable.c";

static void create(int x, int y) {
  ::create(25, 15);
  SetObviousExits("northwest, west, southwest, south, southeast");
  SetExits( ([
    "northwest" : V_ROOM + "24,16",
    "west" : V_ROOM + "24,15",
    "southwest" : V_ROOM + "24,14",
    "south" : V_ROOM + "25,14",
    "southeast" : V_ROOM + "26,14"
  ]) );
}
