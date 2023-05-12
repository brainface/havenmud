// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is iron3.c iron road 3

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "north" : "iron4",
    "south" : "iron2",
    "east" : "eirs3",
    "west" : "wirs3",
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
