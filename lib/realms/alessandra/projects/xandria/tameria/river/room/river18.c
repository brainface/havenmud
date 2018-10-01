//  Alessandra 2011

#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("the river");
  SetLong(
     "This is the river. You are drowning. northeast is more river "
     "south is more river. temple is east with no entrance here. "
     "west is road. north is road."
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
     "north" : TAM_ROOM "rw9",
     "northeast" : TAM_ROOM "river19",
     "south" : TAM_ROOM "river17",
     "west" : TAM_ROOM "rw10",
     ]) );
}
