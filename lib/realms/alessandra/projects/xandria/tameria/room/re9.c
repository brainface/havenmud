//  Alessandra 2011

#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("road east of the river");
  SetLong(
     "This is the road down the east side of the river. Northwest is "
     "more road, southeast is more road. "
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
     "northwest" : TAM_ROOM "re8",
     "south" : TAM_ROOM "river8",
     "southeast" : TAM_ROOM "re10",
     "west" : TAM_ROOM "river7",
     ]) );
}
