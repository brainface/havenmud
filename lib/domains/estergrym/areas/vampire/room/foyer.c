//  Foyer inside a gothic manor
//  Alessandra 2014
#include <lib.h>
#include "../vamp.h"
inherit LIB_ROOM;
static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("the foyer of a gothic manor");
  SetLong(
     "This is a foyer. It's pronounced FoiAy because snooty. "
     );
  SetSmell( ([
     "default" : "This is smells.",
     ]) );
  SetListen( ([
     "default" : "This is noises.",
     ]) );
  SetItems( ([
     ({"foyer"}) : "It's FoiAy, bitches.",
     ]) );
     SetItemAdjectives( ([
     ]) );
  SetInventory( ([
     ]) );
  SetEnters( ([
     ]) );
  SetExits( ([
     "out" : VAMP_ROOM + "courtyard",
     ]) );
}
