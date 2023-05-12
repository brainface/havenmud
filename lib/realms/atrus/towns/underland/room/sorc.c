// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is sorc.c south outer-ring road center

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
   // "west" : "zinc1",
    "north" : "iron1",
    "west" : "sorw1",
    "east" : "sore1",
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
