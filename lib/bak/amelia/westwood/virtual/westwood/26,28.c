#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "river_inheritable.c";

static void create(int x, int y) {
  ::create(26, 28);
  SetObviousExits("northwest, west, southwest, south, southeast");
  SetExits( ([
    "northwest" : V_ROOM + "25,29",
    "west" : V_ROOM + "25,28",
    "southwest" : V_ROOM + "25,27",
    "south" : V_ROOM + "26,27",
    "southeast" : V_ROOM + "27,27",
  ]) );
}
