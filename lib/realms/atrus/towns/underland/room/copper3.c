// The City of Underland
// Atrus@Havenmud 2023
// A gnomish city
// Room is copper3.c copper road 3

#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "north" : "copper2",
    "south" : "copper4",
    "east" : "eirn3",
    "west" : "wirn1",
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
