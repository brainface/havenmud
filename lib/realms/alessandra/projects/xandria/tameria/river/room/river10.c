//  Alessandra 2011

#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("the river");
  SetLong(
     "This is the river. You are drowning. north is more river "
     "south is more river. temple is west with no entrance here. "
     "east is road"
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
     "east" : TAM_ROOM "re12",
     "north" : TAM_ROOM "river9",
     "south" : TAM_ROOM "river11",
     ]) );
}
