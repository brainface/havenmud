//  Gothic Cemetery grounds
//  Alessandra 2014
#include <lib.h>
#include "../vamp.h"
inherit LIB_ROOM;
static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("a gothic cemetery");
  SetLong(
     "There are graves here. I should add zombies because why the fuck not. "
     "I'm adding everything else already. Entrance to tomb/family crypt."
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
//   Enter a tomb/family crypt
     ]) );
  SetExits( ([
     "northeast" : VAMP_ROOM + "cemetery1",
     "northwest" : VAMP_ROOM + "cemetery4",
     "southeast" : VAMP_ROOM + "cemetery2",
     "southwest" : VAMP_ROOM + "cemetery5",
     ]) );
}
