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
     "more road, south is more road. east is more road. west is "
     "the heart of the city."
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
     "east" : TAM_ROOM "re7a",
     "north" : TAM_ROOM "re6",
     "south" : TAM_ROOM "re8",
     "west" : TAM_ROOM "heart",
     ]) );
}
