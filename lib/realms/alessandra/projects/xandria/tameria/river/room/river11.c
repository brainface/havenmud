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
     "southwest is more river. temple is west with no entrance here. "
     "east is road south is road"
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
     "east" : TAM_ROOM "re13",
     "north" : TAM_ROOM "river10",
     "south" : TAM_ROOM "re14",
     "southwest" : TAM_ROOM "river12",
     ]) );
}
