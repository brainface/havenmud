/* This is the seventeen room of the beach coded by Lynna on January 28, 1998
*/

#include <lib.h>
#include "../beach.h"
#include <domains.h>
inherit LIB_ROOM;
static void create() {

	room::create();
	SetShort("a path leading into the woods");
	SetClimate("temperate");
	SetInventory( ([
		BEACH_NPC + "squirrel" : 2,
		]) );
	SetSmell( ([ "default" : "The smell of the sea is mild mixed with "
				 "the smells of the woods." ]) );
	SetListen( ([ "default" : "The crashing of the waves on the shore "
				  "can be heard in the distance." ]) );
	SetLong( "At this point on the path, the true path ends. The woods "
		 "are found to the west, and the sandy shore of the sea to "
		 "the east. The trees above shade the long, narrow path, and "
		 "by looking towards the south, the dark blue sea can be "
		 "seen with the seagulls flying above it." );
	SetItems( ([
		( { "path", "trail", "point" } ) : "This path leads around "
					           "the HavenWood.",
		( { "woods", "trees", "tree" } ) : "These tall, dark trees "
						   "area part of the "
						   "HavenWood.",
		"waves" : "These large white-capped waves cover the sea.",
		( { "shore", "sandy shore" } ) : "This is where the sand "
						 "meets the water's edge.",
		( { "leaves", "leaf" } ) : "The leaves rustle high above in "
					   "the trees.",
		( { "seagulls", "seagull" } ) : "These small birds fly high "
						"above the sea.",
		( { "bird", "birds" } ) : "These seagulls fly high above the "
					  "sea."
		]) );
	SetExits( ([
		"east" : BEACH_ROOM "beach16",
		"south": BEACH_ROOM "beach18",
                "west" : BEACH_ROOM "beach22",
                "northeast" : HAVENWOOD_VIRTUAL "parvapath/0,0",
		]) );
}
