//  Alessandra 2011-2013

#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("bridge market");
  SetLong(
     "The marketplace is enormous and continues to the east and west "
     "as well as to the south. Many merchants have set up various "
     "carts and stalls to take advantage of the large open space. "
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
     "north" : TAM_ROOMR "river2",
     "east" : TAM_ROOM "re3",
     "south" : TAM_ROOM "bridge3",
     "west" : TAM_ROOM "rw3"
     ]) );
}
