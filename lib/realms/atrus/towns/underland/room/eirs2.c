// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is eirs2.c east inner road south 2

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "southwest" : "eirs3",
    "northeast" : "eirs1"
    ]) );
  SetShort("inner ring a copper road");
  SetLong("Inner ring road intersects with copper road.");  
/*
  SetItems( ([
    "tinforge" : "This is the tin forge.",
    ]) );
  SetEnters( ([
    "tinforge" : UNDER_ROOM "tinforge",
    ]) );
*/
}
