//  Gate entrance to cemetery/family tomb
//  Alessandra 2014
#include <lib.h>
#include "../vamp.h"
inherit LIB_ROOM;
static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("an entrance to a gothic cemetery?");
  SetLong(
     "There is a gate here. It keeps you out. Out of the "
     "gothic cemetery. Ok, so it really doesn't keep you out. "
     "But there's still a gate. It's a wide gate cause the path "
     "curves."
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
     "northwest" : VAMP_ROOM + "cemetery1",
     "southwest" : VAMP_ROOM + "cemetery2",
     ]) );
}
