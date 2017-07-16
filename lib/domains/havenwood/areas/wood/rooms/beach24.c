/* This is the last (twenty-fourth) room of the beach coded by Lynna on
		January 28, 1998
*/

#include <lib.h>
#include "../beach.h"
inherit LIB_ROOM;
static void create() {
	room::create();
	SetShort("near the HavenWood");
	SetClimate("temperate");
	SetInventory( ([
		BEACH_OBJ + "acorn" : 1,
		]) );
	SetSmell( ([ "default" : "The scent of the woods is mild combined "
				 "with the smell of the sea." ]) );
	SetListen( ([ "default" : "The crashing of the waves along the "
			          "shore can be heard in the distance." ]) );
	SetLong( "This is the edge of the woods. From this point, the path "
		"is found to the southwest, and by looking towards the "
		 "southeast, the sea and its shores can be seen in the "
		 "distance. The trees here line the long trail that leads "
		 "around the woods and through the sand." );
	SetItems( ([
		( { "woods", "trees", "tree" } ) : "These are the tall, dark "
						   "trees of the HavenWood.",
		"edge" : "The trees here line the dirt-covered path and "
			 "shade the ground.",
		"point" : "From here, the sea, the woods, and the path are "
			  "all visible.",
		( { "sea", "waves", "shore", "shores" } ) : "This is the "
						"eastern sea of Kailie.",
		( { "path", "trail" } ) : "This path leads around the woods.",
		"sand" : "The sand of this beach leads to the eastern sea."
		]) );
	SetExits( ([
		"west" : BEACH_ROOM "beach2",
		"east" : BEACH_ROOM "beach20",
		"north": BEACH_ROOM "beach23"
		]) );
}