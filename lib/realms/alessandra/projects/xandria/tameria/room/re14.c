//  Alessandra 2011

#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("road east of the river");
  SetLong(
     "This is the road on the east side of the river. northeast is "
     "more road, southwest is more road. "
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
     "north" : TAM_ROOM "river11",
     "northeast" : TAM_ROOM "re13",
     "southwest" : TAM_ROOM "rn3",
     "west" : TAM_ROOM "river12",
     ]) );
}
