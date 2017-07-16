//  Updated Soirin Complex
//  Alessandra 2010

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("indoors");
  SetShort("a room of worship");
  SetLong(
     "Altar room / main room of worship / vaulted-ceilings / enormous pews, etc. "
     "West back to church entrance."
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
     "west" : MAL_ROOMS + "church_narthex",
     ]) );
}
