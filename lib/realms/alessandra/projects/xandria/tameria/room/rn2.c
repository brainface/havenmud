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
     "more road, east is more road. south is where zombies are."
     "North is bridge to temple."
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
     "east" : TAM_ROOM "rn3",
     "north" : TAM_ROOM "river13",
     "south" : TAM_ROOM "death",
     "west" : TAM_ROOM "rn1",
     ]) );
}
