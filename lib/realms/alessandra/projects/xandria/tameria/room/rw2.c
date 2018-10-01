//  Alessandra 2011

#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("road west of river");
  SetLong(
     "The foot traffic here between the docks and the open bazaar is "
     "near constant. Merchants haul in new wares while others carry "
     "purchases back out to awaiting ships. The river Parsa runs along "
     "the east side of the road. To the north are the docks and just "
     "south is the open bazaar. "
     );
  SetSmell( ([
     "default" : "Many flavorful scents from the bazaar mingle here.",
     ]) );
  SetListen( ([
     "default" : "The lapping of river water can be heard.",
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
     "east" : TAM_ROOMR "river2",
     "north" : TAM_ROOM "rw1",
     "south" : TAM_ROOM "rw3",
     ]) );
}
