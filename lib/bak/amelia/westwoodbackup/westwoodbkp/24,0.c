#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "lake_inheritable.c";

static void create(int x, int y) {
  ::create(24, 0);
  SetObviousExits("north, northwest, west");
  SetExits( ([
    "north" : V_ROOM + "24,1",
    "northwest" : V_ROOM + "23,1",
    "west" : V_ROOM + "23,0",
  ]) );
}
