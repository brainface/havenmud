// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is wirn3.c west inner road north 3

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "northeast" : "wirn2",
    "south" : "tin3"
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
