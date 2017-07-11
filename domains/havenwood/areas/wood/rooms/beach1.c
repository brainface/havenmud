/* This is my first room of the beach coded by Lynna on January 23, 1998
*/

#include <lib.h>
#include <domains.h>
#include "../beach.h"
inherit LIB_ROOM;
static void create() {

	room::create();
	SetClimate("temperate");
	SetSmell( ([ "default" : "The smell of the sea is very mild but "
				 "present." ]) );
	SetListen( ([ "default" : "The crashing of waves can be heard in the "
				  "distance." ]) );
	SetShort("near the HavenWood");
	SetLong("This path leads to the beach near the HavenWood. The trees "
		"are tall and line the dirt-covered path, covering it with "
		"shade. The smooth sand can be seen along with the dark "
		"waters of the sea.");
	SetInventory( ([
		BEACH_NPC + "chipmunk" : 1,
		]) );
	SetItems( ([ 
		"sea"    : "The eastern waters of Kailie are dark and cold.",
		( { "ground", "path", "dirt-covered path" } ) : "The "
					"dirt-covered path leads through the "
					"woods and to the sea.",
		"beach"  : "The sand covers the ground that leads to the "
			   "dark waters.",
		( { "tree", "trees", "woods" } ) : "The tall trees line and "
				                   "shade the path.",
		( { "sand", "smooth sand" } ) : "The sand is a tan color and "
						"looks smooth from a "
						"distance.",
		( { "water", "dark waters", "waters", "dark water", "eastern "
		    "water", "eastern waters" } ) : " The dark water is all "
					"that can be seen while peering "
					"towards the sea.",
		( { "trees", "tree", "tall trees", "tall tree" } ) : "The " 
					"tall trees line and shade the path.",
		"shade"  : "The shade accounts for the coolness in the air."
		     ]) );
	SetExits( ([
		"south" : BEACH_ROOM "beach2",
                "west"  : HAVENWOOD_TOWNS "havenwood/room/gelf6",
		"east"  : BEACH_ROOM "beach23",
		]) );
		}
