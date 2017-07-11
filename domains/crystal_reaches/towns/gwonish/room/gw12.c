#include <lib.h>
#include <domains.h>
#include "../gwonish.h"
inherit LIB_ROOM;

static void create() {
	::create(); SetClimate("sub-tropical");
	SetShort("near a small village");
	SetDayLight(-10);
	SetNightLight(-10);
	SetExits( ([
	  "east"      : GWONISH_ROOM "gw13",
	  "northwest" : CRYSTAL_REACHES_AREAS "gwonish/room/swamp5",
	  ]) );
	SetLong("The swamp becomes thick and dark here, with trees hanging "
	        "overhead preventing enough light from entering the swampy "
	        "terrain. A thin path leads off to the east, deeper into "
	        "the swamp. To the northwest, the path leads out into the "
	        "main heart of Gwonish Swamp.");
	SetListen( ([
	  "default" : "Birds caw loudly deep inside the swamp.",
	  ]) );
	SetSmell( ([
	  "default" : "The swamp smells of rotting vegetation.",
	  ]) );
	SetInventory( ([
	  GWONISH_NPC "guard" : 1,
	  ]) );
	SetItems( ([
	  ({ "tree", "trees" }) : "The trees overhead dim the light somewhat "
	                          "and make the swamp that much more ominous.",
	     "path"             : "The path is thin and almost impassible.",
	  ]) );                     
}