// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is center.c Center Square

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "west" : "tin5",
    "east" : "zinc5",
    "north" : "copper5",
    "south" : "iron5",
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
