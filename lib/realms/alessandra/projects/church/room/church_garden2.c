//  Updated Soirin Complex
//  Alessandra 2009

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
 	
  SetClimate("indoors");
  SetShort("church garden");
  SetLong(
     "Garden. South to garden entrance."
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
     "south" : MAL_ROOMS + "church_garden1",
     ]) );
 }
