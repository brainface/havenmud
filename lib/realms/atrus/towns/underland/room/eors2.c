// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is eors2.c east outer-ring road south 2

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
   // "west" : "zinc1",
   // "east" : "egate2",
    "southwest" : "eorse1",
    "north" : "eors1",
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

