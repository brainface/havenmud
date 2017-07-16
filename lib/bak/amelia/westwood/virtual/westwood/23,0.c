#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "lake_inheritable.c";

static void create(int x, int y) {
  ::create(23, 0);
  SetObviousExits("east, northeast, north, northwest, west");
  SetExits( ([
    "east" : V_ROOM + "24,0",
    "northeast" : V_ROOM + "24,1",
    "north" : V_ROOM + "23,1",
    "northwest" : V_ROOM + "22,1",
    "west" : V_ROOM + "22,0",
  ]) );
}
