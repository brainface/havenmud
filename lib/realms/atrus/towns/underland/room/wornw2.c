// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is wornw2.c west outer-ring road north west 2

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    //"west" : "gate2",
    //"east" : "tin1",
    "northeast" : "wornw3",
    "southwest" : "wornw1",
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
