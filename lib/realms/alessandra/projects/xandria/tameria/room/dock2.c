//  Alessandra 2011

#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("east of the dock");
  SetLong(
     "This is  not where the actual dock is. North is the sea, south is "
     "a road down the east side of the river. west is stuff."
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
//     "north" : the sea,
     "south" : TAM_ROOM "re1",
     "west" : TAM_ROOM "bridge1",
     ]) );
}
