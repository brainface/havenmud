//  Alessandra 2011

#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("the river");
  SetLong(
     "This is the river. You are drowning. northwest is more river "
     "south is more river. temple is west with no entrance here. "
     "north and east are roads"
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
     "east" : TAM_ROOM "re10",
     "north" : TAM_ROOM "re9",
     "northwest" : TAM_ROOM "river7",
     "south" : TAM_ROOM "river9",
     ]) );
}
