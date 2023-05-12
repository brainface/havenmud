// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is wirs3.c west inner road south 3

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "east" : "iron3",
    "northwest" : "wirs2",
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
