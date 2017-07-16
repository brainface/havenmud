//  Alessandra 2011

#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("road west of river");
  SetLong(
     "This is the road down the west side of the river. Northeast is "
     "more road, southwest is more road. Enter is temple to SE."
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
     "east" : TAM_ROOM "river19",
     "northeast" : TAM_ROOM "rw8",
     "south" : TAM_ROOM "river18",
     "southwest" : TAM_ROOM "rw10",
     ]) );
}
