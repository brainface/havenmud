// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is sorw1.c south outer-ring road west 1

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
   // "west" : "zinc1",
   // "north" : "iron1",
    "west" : "sorw2",
    "east" : "sorc",
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
