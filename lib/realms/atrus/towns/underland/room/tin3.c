// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is tin3.c Tin Road 3

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "north" : "wirn3",
    "south" : "wirs1",
    "west" : "tin2",
    "east" : "tin4",
    ]) );
  SetShort("outer ring road west");
  SetLong("This is the outer ring road.");  
/*
  SetItems( ([
    "tinforge" : "This is the tin forge.",
    ]) );
  SetEnters( ([
    "tinforge" : UNDER_ROOM "tinforge",
    ]) );
*/
}
