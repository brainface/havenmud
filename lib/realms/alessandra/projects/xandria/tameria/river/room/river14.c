//  Alessandra 2011

#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("the river");
  SetLong(
     "This is the river. You are drowning. east is more river "
     "northwest is more river. temple is north with no entrance here. "
     "south is road. west is road"
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
     "east" : TAM_ROOM "river13",
     "northwest" : TAM_ROOM "river15",
     "south" : TAM_ROOM "rn1",
     "west" : TAM_ROOM "rw14",
     ]) );
}
