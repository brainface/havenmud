#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "river_inheritable.c";

static void create(int x, int y) {
  ::create(26, 23);
  SetObviousExits("northwest, west, southwest, south, southeast");
  SetExits( ([
    "northwest" : V_ROOM + "25,24",
    "west" : V_ROOM + "25,23",
    "southwest" : V_ROOM + "25,22",
    "south" : V_ROOM + "26,22",
    "southeast" : V_ROOM + "27,22",
  ]) );
}
