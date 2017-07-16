#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "river_inheritable.c";

static void create(int x, int y) {
  ::create(27, 27);
  SetObviousExits("northwest, west, southwest, south");
  SetExits( ([
    "northwest" : V_ROOM + "26,28",
    "west" : V_ROOM + "26,27",
    "southwest" : V_ROOM + "26,26",
    "south" : V_ROOM + "27,26",
  ]) );
}
