// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is wornw3.c west outer-ring road north west 3

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    //"west" : "gate2",
    //"east" : "tin1",
    "northeast" : "norn1",
    "southwest" : "wornw2",
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
