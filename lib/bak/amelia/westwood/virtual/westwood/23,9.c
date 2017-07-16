#include <lib.h>
#include "../westwood.h"
inherit V_ROOM + "lake_inheritable.c";

static void create(int x, int y) {
  ::create(23, 9);
  SetExits( ([
    "east" : V_ROOM + "24,9",
    "northeast" : V_ROOM + "24,10",
    "north" : V_ROOM + "23,10",
    "northwest" : V_ROOM + "22,10",
    "west" : V_ROOM + "22,9",
    "southwest" : V_ROOM + "22,8",
    "south" : V_ROOM + "23,8",
  ]) );
}
