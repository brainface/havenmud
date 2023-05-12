#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the north of the foreign district");
  SetExits( ([
    "south" : UNDER_ROOM "level0hub",
        ]) );
  SetSmell("The smells of gnomish stuff.");
  SetListen("Stuff.");
  SetLong("The long goes here"
    );
  SetItems( ([
    ({ "mountain", "mount", "trog" }) : "Mount Trog is down the "
                                        "road to the east.",
    ({ "tavern", "building" }) : "tavern.",
    ]) );
  SetEnters( ([
    "tavern" : UNDER_ROOM "tavern",
    ]) );
  SetInventory( ([
    UNDER_NPC "guard" : random(2),
    ]) );
}
