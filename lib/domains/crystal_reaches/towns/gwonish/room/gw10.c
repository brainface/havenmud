#include <lib.h>
#include "../gwonish.h"
inherit LIB_ROOM;

static void create() {
	::create(); SetClimate("sub-tropical");
	SetShort("near the center of the village");
	SetExits( ([
	  "southeast" : GWONISH_ROOM "gw07",
	  "east"      : GWONISH_ROOM "gw11",
	  "west"      : GWONISH_ROOM "gw09",
	  "south"     : GWONISH_ROOM "gw06",
	  ]) );
	SetLong("The swamp begins to open up a bit here as it leads closer to the "
	        "heart of the village. Off to the southeast is the apparent "
	        "\"center\" of the town. The trees of the swamp are less dense "
	        "here, allowing some light to come in from the sky. A thin marshy "
	        "path heads off to the east and west from here.");
  SetItems( ([
    ({ "tree", "trees" }) : "The trees are less dense here.",
    ]) );
  SetListen( ([
    "default" : "The trees rustle with every slight breeze.",
    ]) );
  SetSmell( ([
    "default" : "The smell of decayed swamplife oozes to the surface.",
    ]) );
  SetInventory( ([
    ]) );
}