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
     "southwest is more river. temple is south with no entrance here. "
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
     "east" : TAM_ROOM "river6",
     "north" : TAM_ROOM "rw8",
     "southwest" : TAM_ROOM "river18",
     "west" : TAM_ROOM "rw9",
     ]) );
}
