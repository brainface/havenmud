#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("in the center of the market district");
  SetExits( ([
    "south" : UNDER_ROOM "level2hub",
        ]) );
  SetSmell("The smells of gnomish stuff.");
  SetListen("Stuff.");
  SetLong("The long goes here"
    );
  SetItems( ([
    ({ "mountain", "mount", "trog" }) : "Mount Trog is down the road to the east.",
    ({ "armoury", "building" }) : "Armoury.",
    ]) );
  SetEnters( ([
    "armoury" : UNDER_ROOM "armoury",
    ]) );
  SetInventory( ([
    UNDER_NPC "guard" : random(3),
    ]) );
}
