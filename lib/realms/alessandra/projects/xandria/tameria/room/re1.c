//  Alessandra 2011

#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("road by the dock");
  SetLong(
     "This is the road down the east side of the river. North is "
     "a room by the sea, south is more road."
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
     "north" : TAM_ROOM "dock2",
     "south" : TAM_ROOM "re2",
     "west" : TAM_ROOM "river1",
     ]) );
}
