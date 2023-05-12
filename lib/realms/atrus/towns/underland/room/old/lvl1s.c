#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("south municipal district");
  SetExits( ([
    "north" : UNDER_ROOM "level1hub"
        ]) );
  SetSmell("The smells of gnomish stuff.");
  SetListen("Stuff.");
  SetLong("The long goes here"
    );
  SetItems( ([
    ({ "mountain", "mount", "trog" }) : "Mount Trog is down the road to the east.",
    ({ "charity", "building" }) : "charity building.",
    ]) );
  SetEnters( ([
    "charity" : UNDER_ROOM "newbie",
    ]) );
  SetInventory( ([
    UNDER_NPC "guard" : 1,
    ]) );
}
