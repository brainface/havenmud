//  Updated Soirin Complex
//  Alessandra 2009

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
 	
  SetClimate("indoors");
  SetShort("garden entrance");
  SetLong(
     "Entrance from main pathway. This is a garden. East is Church entrance. "
     "North and south are continued garden."
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
     "out" : MAL_ROOMS + "path11",
     "north" : MAL_ROOMS + "church_garden2",
     "south" : MAL_ROOMS + "church_garden3",
     "east" : MAL_ROOMS + "church_narthex",
     ]) );
 }
