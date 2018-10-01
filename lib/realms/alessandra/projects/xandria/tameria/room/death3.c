
#include <lib.h>
#include "../tam.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("arid");
  SetShort("a thingy leading to something else");
  SetLong(
     "Spiraly staircase up to new and better death? Umm, yes please. "
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
     "up" : TAM_ROOM "death4",
     "down" : TAM_ROOM "death2",
     ]) );
}
