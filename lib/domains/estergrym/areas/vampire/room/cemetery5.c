//  Gothic Cemetery grounds
//  Alessandra 2014
#include <lib.h>
#include "../vamp.h"
inherit LIB_ROOM;
static void create() {
  room::create();
  SetClimate("outdoors");
  SetShort("a gothic cemetery");
  SetLong(
     "There are graves here. I should add zombies because why the fuck not. "
     "I'm adding everything else already. Tomb north. No Entrance. Secret "
     "entrance from gypsy camp area forest16."
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
     "northeast" : VAMP_ROOM + "cemetery3",
     ]) );
}
