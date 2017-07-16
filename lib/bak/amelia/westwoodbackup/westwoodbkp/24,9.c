#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "lake_inheritable.c";

static void create(int x, int y) {
  ::create(24, 9);
  SetObviousExits("north, northwest, west, southwest");
  SetExits( ([
    "north" : V_ROOM + "24,10",
    "northwest" : V_ROOM + "23,10",
    "west" : V_ROOM + "23,9",
    "southwest" : V_ROOM + "23,8",
  ]) );
}
