// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is norn.c north outer-ring road 1

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    //"west" : "gate2",
    //"east" : "tin1",
    "east" : "norn2",
    "southwest" : "wornw3",
    ]) );
  SetShort("outer ring road west");
  SetLong("This is the outer ring road, along the west side, intersecting tin road.");  
/*
  SetItems( ([
    "tinforge" : "This is the tin forge.",
    ]) );
  SetEnters( ([
    "tinforge" : UNDER_ROOM "tinforge",
    ]) );
*/
}
