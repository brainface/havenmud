//  Alessandra 2011

#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("road west of river");
  SetLong(
     "This is the road down the west side of the river. North is "
     "the more road, southwest is more road."
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
     "east" : TAM_ROOM "river5",
     "north" : TAM_ROOM "rw7",
     "south" : TAM_ROOM "river19",
     "southwest" : TAM_ROOM "rw9",
     ]) );
}
