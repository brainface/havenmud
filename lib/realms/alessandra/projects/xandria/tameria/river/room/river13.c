//  Alessandra 2011

#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("a bridge across the river");
  SetLong(
     "East and West is more river. South is towards death. North is Temple. "
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
     "east" : TAM_ROOM "river12",
     "south" : TAM_ROOM "rn2",
     "north" : TAM_ROOM "temple1",
     "west" : TAM_ROOM "river14",
     ]) );
}
