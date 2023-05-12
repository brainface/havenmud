#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the city hall");
  SetExits( ([
    "out" : UNDER_ROOM "level1hub"
        ]) );
  SetSmell("The smells of gnomish stuff.");
  SetListen("Stuff.");
  SetLong("The long goes here"
    );
  SetItems( ([
    ({ "mountain", "mount", "trog" }) : "Mount Trog is down the road to the east.",
    ({ "hall", "building" }) : "cityhall.",
    ]) );
  SetInventory( ([
    UNDER_NPC "mayor" : 1,
    ]) );
}
