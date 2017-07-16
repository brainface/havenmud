#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "lake_inheritable.c";

static void create(int x, int y) {
  ::create(23, 6);
  SetObviousExits("north, northwest, west, southwest");
  SetExits( ([
    "north" : V_ROOM + "23,7",
    "northwest" : V_ROOM + "22,7",
    "west" : V_ROOM + "22,6",
    "southwest" : V_ROOM + "22,5",
  ]) );
}
