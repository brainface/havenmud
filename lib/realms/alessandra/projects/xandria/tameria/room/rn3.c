//  Alessandra 2011

#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("road south of the river");
  SetLong(
     "This is the road on the south side of the river. west is "
     "more road, northeast is more road. "
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
     "northeast" : TAM_ROOM "re14",
     "north" : TAM_ROOM "river12",
     "west" : TAM_ROOM "rn2",
     ]) );
}
