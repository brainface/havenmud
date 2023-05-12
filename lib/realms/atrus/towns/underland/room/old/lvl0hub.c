#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the center of the foreign district");
  SetExits( ([
    "east" : UNDER_ROOM "level0east",
    "west" : UNDER_ROOM "level0west",
    "north" : UNDER_ROOM "level0north",
    "south" : UNDER_ROOM "level0south",
    "down" : UNDER_ROOM "level1hub",
        ]) );
  SetSmell("The smells of gnomish stuff.");
  SetListen("Stuff.");
  SetLong("The long goes here"
    );
  SetItems( ([
    ({ "mountain", "mount", "trog" }) : "Mount Trog is down the road to the
east.",
    ({ "hall", "building" }) : "cityhall.",
    ]) );
  SetEnters( ([
    "hall" : UNDER_ROOM "magic",
    ]) );
  SetInventory( ([
    UNDER_NPC "guard" : random(3),
    ]) );
}
