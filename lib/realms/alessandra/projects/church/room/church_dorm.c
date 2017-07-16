//  Updated Soirin Complex
//  Alessandra 2010

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("indoors");
  SetShort("a living space");
  SetLong(
     "Dormitory. Sleeping, etc. for clerics/priests.. whatever."
     );
  SetSmell( ([
     "default" : "This is smells.",
     ]) );
  SetListen( ([
     "default" : "This is noises.",
     ]) );
  SetItems( ([
     ]) );
  SetItemAdjectives( ([
     ]) );
  SetInventory( ([
     ]) );
  SetEnters( ([
     ]) );
  SetExits( ([
     "south" : MAL_ROOMS + "church_library",
     ]) );
}
