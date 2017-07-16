#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("west municipal district");
  SetExits( ([
    "east" : UNDER_ROOM "level1hub"
        ]) );
  SetSmell("The smells of gnomish stuff.");
  SetListen("Stuff.");
  SetLong("The long goes here"
    );
  SetItems( ([
    ({ "mountain", "mount", "trog" }) : "Mount Trog is down the road to the east.",
    ({ "store", "building" }) : "store.",
    ]) );
  SetEnters( ([
    "store" : UNDER_ROOM "shop",
    ]) );
  SetInventory( ([
    UNDER_NPC "guard" : 1,
    ]) );
}
