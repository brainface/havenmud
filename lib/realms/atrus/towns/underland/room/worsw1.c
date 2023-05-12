// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is worsw1.c west outer-ring road southwest 1

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
   // "west" : "zinc1",
   // "north" : "iron1",
    "southeast" : "worsw2",
    "northwest" : "wors2",
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
