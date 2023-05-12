#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "south" : "level1hub",
    ]) );
  SetShort("a high gated church");
  SetLong(
    "A big ass church sits to the north."
    );
  SetSmell("The smell of oil and parchment is here.");
  SetListen("The sounds of gears and cogs slowly turning against each other fills the air.");
  SetItems( ([
    ({ "mountain", "mount", "trog" }) : "Mount Trog is down the road to the east.",
    ({ "church", "building" }) : "Healer file name.",
    ]) );
  SetEnters( ([
    "church" : UNDER_ROOM "healer",
    ]) );
  SetInventory( ([
    UNDER_NPC "guard" : random(3),
    ]) );
}
