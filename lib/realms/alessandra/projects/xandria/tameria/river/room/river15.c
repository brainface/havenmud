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
     "southeast is more river. temple is east with no entrance here. "
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
     "north" : TAM_ROOM "river16",
     "south" : TAM_ROOM "rw14",
     "southeast" : TAM_ROOM "river14",
     "west" : TAM_ROOM "rw13",
     ]) );
}
