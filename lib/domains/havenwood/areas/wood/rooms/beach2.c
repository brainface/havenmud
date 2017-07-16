/* This is the second room of the beach coded by Lynna on January 28, 1998
*/

#include <lib.h>
#include "../beach.h"
inherit LIB_ROOM;
static void create() {

	room::create();
	SetClimate("temperate");
	SetSmell( ([ "default" : "The salty-smell of the sea is mild." ]) );
	SetListen( ([ "default" : "The crashing of the waves into the shore "
				  "can be heard in the distance." ]) );
	SetInventory( ([
		BEACH_OBJ + "rock" : 1,
		]) );
	SetShort("near the HavenWood");
	SetLong("This path near the woods is long and narrow. Along the edge "
		"of the dirt-covered path, the trees are tall and cover the "
		"ground with shade. The sea and its sandy beach can be seen "
		"in the distance.");
	SetItems( ([ 
		( { "waves", "sea" } ) : "These waves are large and "
					 "white-capped.",
		"edge"  : "The trees meet the path at this point on the "
			  "ground.",
		"point" : "This point on the path is where the tall trees "
			  "meet the ground.",
		"shore" : "The shore of this sea is sandy but covered "
			  "with stones.",
		( { "stones", "stone" } ) : "These stones are small, but " 
					    "sharp.",
		( { "path", "dirt-covered path" } ) : "This is a dirt-covered "
						"path leading from the "
						"woods.",
		( { "tree", "trees", "tall tree", "tall trees", "woods" } ) : 
						"The trees here are tall and "
						"shady.",
		"ground": "The ground here is just the path.",
		"shade" : "The shade make the ground dark, and feels cool.",
		( { "beach", "sandy beach" } ) : "The beach consists of the "
						"sand and the shore "
						"of the sea of Kailie.",
		]) );
	SetExits(  ([
		"north" : BEACH_ROOM "beach1",
		"south" : BEACH_ROOM "beach3",
		"east"  : BEACH_ROOM "beach24"
		]) );
}
