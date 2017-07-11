//  Gothic family tomb
//  Alessandra 2014
#include <lib.h>
#include "../vamp.h"
inherit LIB_ROOM;
static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("a gothic tomb");
  SetLong(
     "Dead stuff. And stuff. Possible secret entrance to more tomb raiding."
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
     "out" : VAMP_ROOM + "cemetery3",
     ]) );
}
