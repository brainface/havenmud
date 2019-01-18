
//  Garden grounds outside a gothic manor
//  Alessandra 2014
#include <lib.h>
#include "../vamp.h"
inherit LIB_ROOM;
static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("the garden grounds of a gothic manor");
  SetLong(
     "This is a sprawling lawn. It is totes not creepy. The manor "
     "probs might be. A Little bit."
     );
  SetSmell( ([
     "default" : "This is smells.",
     ]) );
  SetListen( ([
     "default" : "This is noises.",
     ]) );
  SetItems( ([
     ({"manor"}) : "It's gothic.",
     ]) );
  SetItemAdjectives( ([
     ]) );
  SetInventory( ([
     ]) );
  SetEnters( ([
     ]) );
  SetExits( ([
     "west" : VAMP_ROOM + "courtyard",
     ]) );
}
