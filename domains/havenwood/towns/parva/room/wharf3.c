#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "east" : PARVA_ROOM "docks1",
    "north": PARVA_ROOM "wharf2",
    "south": PARVA_ROOM "wharf4",
    ]) );
  SetShort("along the wharf in Parva");
  SetLong(
    "The road continues north and south from here between the "
    "broken-down buildings of Parva and the ocean to the east. To "
    "the south stand the swaying docks, jutting out into the water, and "
    "just north is a small obsidian structure."
  );
  SetItems( ([
    ]) );
  SetItemAdjectives( ([
    ]) );
  SetEnters( ([
    ]) );
  SetSmell("The stench of the ocean assaults the air.");
  SetListen("The crash of the waves can be heard from the east.");
  SetInventory( ([
    ]) );
}

