//  Garden trail to cemetery/family plots
//  Alessandra 2014
#include <lib.h>
#include "../vamp.h"
inherit LIB_ROOM;
static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("garden trail");
  SetLong(
     "This is a gardeny trail. Creepy as shit. Because Cemetery "     
     "somewhere close. "
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
     "northwest" : VAMP_ROOM + "cemeterygate",
     "southeast" : VAMP_ROOM + "gardenwest",
     ]) );
}
