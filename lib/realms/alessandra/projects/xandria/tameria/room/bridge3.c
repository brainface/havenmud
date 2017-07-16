//  Alessandra 2011

#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("bridge market");
  SetLong(
     "This is a bridge over the river. west is road. east is road. "
     "north is more bridge - this should be huge open market "
     "spanning all adjoining rooms."
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
     "east" : TAM_ROOM "re4",
     "north" : TAM_ROOM "bridge2",
     "west" : TAM_ROOM "rw4",
     ]) );
}
