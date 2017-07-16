#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "lake_inheritable.c";

static void create(int x, int y) {
  ::create(24, 2);
  SetObviousExits("west, southwest, south");
  SetExits( ([
    "west" : V_ROOM + "23,2",
    "southwest" : V_ROOM + "23,1",
    "south" : V_ROOM + "24,1",
  ]) );
}
