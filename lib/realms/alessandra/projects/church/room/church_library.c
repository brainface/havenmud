//  Updated Soirin Complex
//  Alessandra 2010

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("indoors");
  SetShort("church library or something");
  SetLong(
     "Library. North to some kind of living space. Add wandering priests / "
     "priestesses. Down to main church entrance. SECRET ROOM TO BE ADDED "
     "FROM HERE - leads to hidden Mel altar/statue.. rat kids, etc."
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
     "north" : MAL_ROOMS + "church_dorm",
     "down" : MAL_ROOMS + "church_narthex",
     ]) );
}
