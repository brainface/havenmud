#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("in the south of the market district");
  SetExits( ([
    "north" : UNDER_ROOM "level2hub",
        ]) );
  SetSmell("The smells of gnomish stuff.");
  SetListen("Stuff.");
  SetLong("The long goes here"
    );
  SetItems( ([
    ({ "mountain", "mount", "trog" }) : "Mount Trog is down the road to the east.",
    ({ "barracks", "building" }) : "barracks.",
    ]) );
  SetEnters( ([
    "barracks" : UNDER_ROOM "barracks",
    ]) );
  SetInventory( ([
    UNDER_NPC "guard" : random(3),
    ]) );
}
