#include <lib.h>
#include "../gwonish.h"
inherit LIB_ROOM;

static void create() {
	::create(); SetClimate("sub-tropical");
	SetShort("a winding path through Gwonish Swamp");
	SetExits( ([
	  "west"  : GWONISH_ROOM "gw10",
	  "north" : GWONISH_ROOM "gw13",
	  ]) );
	SetDayLight(-10);
	SetNightLight(-10);
	SetLong("The path continues to meander through the swamp here, "
	        "heading off to the north and west. To the north, the "
	        "path leads away from the village center, while to the "
	        "west it leads deeper into the swamp. The trees overhead "
	        "block out some light, making this swamp dark and evil.");
	SetListen( ([
	  "default" : "Occasionally the muck bubbles and releases gas.",
	  ]) );
  SetSmell( ([
    "default" : "The swamp smells of rotting vegetation.",
    ]) );
  SetItems( ([
    ({ "tree", "trees" }) : "The trees block the light from fully "
                            "reaching the swamp floor.",
    ]) );
  SetInventory( ([
    GWONISH_NPC "turtle" : 1,
    ]) );
}