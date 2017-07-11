//  Dead forest path to Gothic Manor
//  Alessandra 2013
#include <lib.h>
#include "../vamp.h"
inherit LIB_ROOM;
static void create() {
  room::create();
  SetClimate("outdoors");
  SetShort("the courtyard of a gothic manor");
  SetLong(
     "No, you are STILL not in the actual manor. But, damnit, "
     "you're close. I promise. There's actually a manor here. "
     "Somewhere. "
     );
  SetSmell( ([
     "default" : "This is smells.",
     ]) );
  SetListen( ([
     "default" : "This is noises.",
     ]) );
  SetItems( ([
     ({"manor"}) : "It's gothic.",
     ]) );
  SetItemAdjectives( ([
     ]) );
  SetInventory( ([
     ]) );
  SetEnters( ([
     "manor" : VAMP_ROOM + "foyer",
     ]) );
  SetExits( ([
     "east" : VAMP_ROOM + "gardeneast",
     "west" : VAMP_ROOM + "gardenwest",
     "south" : VAMP_ROOM + "gate",
     ]) );
}
