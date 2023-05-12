// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is zinc3.c zinc road 3

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "north" : "eirn1",
    "south" : "eirs1",
    "west" : "zinc4",
    "east" : "zinc2",
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
