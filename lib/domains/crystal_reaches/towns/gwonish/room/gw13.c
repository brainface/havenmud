#include <lib.h>
#include "../gwonish.h"
inherit LIB_ROOM;

static void create() {
	::create(); SetClimate("sub-tropical");
	SetShort("a curve in the swamp path");
	SetExits( ([
	  "west"  : GWONISH_ROOM "gw12",
	  "south" : GWONISH_ROOM "gw11",
	  ]) );
	SetListen( ([
	  "default" : "Animals rustle the trees in the swamp.",
	  ]) );
	SetSmell( ([
	  "default" : "The smells of rotting vegetation taint the air.",
	  ]) );
	SetLong("The path curves from the west to the south here, continuing "
	        "deeper into the swamp to the south and leading out of the "
	        "village to the west. Lying on a small patch of firm ground "
	        "is a wooden building with stone and metal supports. The "
	        "trees overhead seem to blot out some of the light from the "
	        "sky.");
	SetItems( ([
	  ({ "tree", "trees" }) : "The overhead trees block some of the "
	                          "light from the sky.",
       "building"         : "The building is a barracks of some sort.",
    ]) );
  SetItemAdjectives( ([
    "building" : ({ "wooden" }),
    ]) );
  SetEnters( ([
    "building" : GWONISH_ROOM "barracks",
    ]) );
  SetDayLight(-10);
  SetNightLight(-10);
  SetInventory( ([
    GWONISH_NPC "raider" : 2,
  ]) );
}
