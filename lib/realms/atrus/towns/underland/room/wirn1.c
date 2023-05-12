// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is wirn1.c west inner road north 1

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "east" : "copper3",
    "southwest" : "wirn2"
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
