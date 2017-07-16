#include <lib.h>
#include "../gwonish.h"
inherit LIB_ROOM;

static void create() {
	::create(); SetClimate("sub-tropical");
	SetShort("the center of the village");
	SetExits( ([
	  "northwest" : GWONISH_ROOM "gw10",
	  "east"  : GWONISH_ROOM "gw08",
	  "west"  : GWONISH_ROOM "gw06",
	  "south" : GWONISH_ROOM "gw02",
	  ]) );
	SetInventory( ([
	  GWONISH_OBJ "pool" : 1,
	  ]) );
  SetLong("The path opens up here to reveal what can only be considered "
          "the center of the village. Paths head off in many directions, "
          "some heading towards the swamp and others heading off towards "
          "more useful areas of the village. ");
  SetSmell( ([
    "default" : "Rotting vegatation gives the swamp a strange scent.",
    ]) );
  SetListen( ([
    "default" : "Water bubbles in the pool.",
    ]) );
    
}