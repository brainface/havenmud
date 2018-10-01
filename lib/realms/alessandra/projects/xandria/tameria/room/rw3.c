//  Alessandra 2011-2013

#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("road west of river");
  SetLong(
     "The open bazaar starts here and spans both to the south and "
     "to the east across the bridge. It is one of the largest open "
     "spaces in town and many merchants set up their carts and stalls "
     "to take advantage of the location. To the north are the docks "
     "and to the south past the bazaar goes further into the heart "
     "of town."
     );
  SetSmell( ([
     "default" : "The air smells strongly of fish.",
     ]) );
  SetListen( ([
     "default" : "The sounds of merchants plying their wares can be heard.",
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
     "east" : TAM_ROOM "bridge2",
     "north" : TAM_ROOM "rw2",
     "south" : TAM_ROOM "rw4",
     ]) );
}
