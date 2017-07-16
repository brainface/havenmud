#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "river_inheritable.c";

static void create(int x, int y) {
  ::create(27, 22);
  SetObviousExits("northwest, west, southwest");
  SetExits( ([
    "northwest" : V_ROOM + "26,23",
    "west" : V_ROOM + "26,22",
    "southwest" : V_ROOM + "26,21",
  ]) );
}
