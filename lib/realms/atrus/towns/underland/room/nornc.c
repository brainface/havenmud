// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is nornc.c north outer-ring road center

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    //"west" : "gate2",
    "south" : "copper1",
    "east" : "norn4",
    "west" : "norn2",
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
