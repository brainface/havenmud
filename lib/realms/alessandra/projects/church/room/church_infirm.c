//  Updated Soirin Complex
//  Alessandra 2009

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
 	
  SetClimate("indoors");
  SetShort("church room");
  SetLong(
     "Church safe room or possibly healer here. South to main church entrance."
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
     "south" : MAL_ROOMS + "church_narthex",
     ]) );
 }
