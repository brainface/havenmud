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
     "Garden. North to garden entrance. East to Cemetery."
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
     "north" : MAL_ROOMS + "church_garden1",
     "east" : MAL_ROOMS + "church_mausoleum",
     ]) );
 }
