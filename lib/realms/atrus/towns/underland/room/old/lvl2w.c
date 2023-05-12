#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("in the west of the market district");
  SetExits( ([
    "east" : UNDER_ROOM "level2hub",
        ]) );
  SetSmell("The smells of gnomish stuff.");
  SetListen("Stuff.");
  SetLong("The long goes here"
    );
  SetItems( ([
    ({ "mountain", "mount", "trog" }) : "Mount Trog is down the road to the east.",
    ({ "shop", "building" }) : "barracks.",
    ]) );
  SetEnters( ([
    "shop" : UNDER_ROOM "shop",
    ]) );
  SetInventory( ([
    UNDER_NPC "guard" : random(3),
    ]) );
}
