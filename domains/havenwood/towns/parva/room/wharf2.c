#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

int PreventLeaveParva();

static void create() {
  ::create();
  SetExits( ([
    "north" : PARVA_ROOM "wharf1",
    "south" : PARVA_ROOM "wharf3",
    ]) );
  SetShort("along the wharf in Parva");
  SetLong(
    "The road which runs through this rundown seaside town "
    "passes here by a small building, sheathed entirely in obsidian, "
    "a shrine of some kind. North is another shrine and more of "
    "the town, and the Parvan docks stand just south of here."
  );
  SetItems( ([
    "road" : "The road is a sandy path, kept mostly free of debris.",
    "building" : "The building is a Soirin shrine.",
    "docks" : "The docks jut out into the water to the south.",
    "shrine" : "This is a Soirin shrine, dedicated the Goddess of Lust and Greed.",
    ]) );
  SetItemAdjectives( ([
    "building" : ({"small", "obsidian"}),
    "docks" : "parvan",
    ]) );
  SetEnters( ([
    "shrine" : PARVA_ROOM "soirin",
    ]) );
  SetSmell("The stench of the sea assaults the air.");
  SetListen("Strange noises come from the shrine.");
  SetInventory( ([
    ]) );
}
