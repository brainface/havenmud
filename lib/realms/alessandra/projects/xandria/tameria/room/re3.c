//  Alessandra 2011

#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("road east of the river");
  SetLong(
     "This is the road down the east side of the river. North is "
     "more road, south is more road. west is a bridge"
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
     "north" : TAM_ROOM "re2",
     "south" : TAM_ROOM "re4",
     "west" : TAM_ROOM "bridge2",
     ]) );
}
