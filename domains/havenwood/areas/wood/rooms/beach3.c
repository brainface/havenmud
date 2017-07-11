/* This is the third room of the beach coded by Lynna on January 28, 1998
*/

#include <lib.h>
#include "../beach.h"
inherit LIB_ROOM;
static void create() {

	room::create();
	SetShort("a path leading from the HavenWood" );
	SetLong("This path leading from the woods is long and narrow. Along "
 		"the side of the dirt-covered path the sand has started to "
		"cover the ground. The sea can be seen from this point on the "
		"path, and it is only a short walk to the water. ");
	SetClimate("temperate");
	SetSmell( ([ "default" : "The strong salty smell of the sea is in the "
				 "air." ]) );
	SetListen( ([ "default" : "The crashing of the waves against the "
				  "shore is loud and soothing." ]) );
	SetInventory( ([
		BEACH_NPC + "turtle" : 1,
		BEACH_NPC + "duck"   : 1,
		]) );
	SetItems( ([ 
		( { "path", "dirt-covered path", "point" } ) : "This path is "
						       "long and leads "
						       "through the woods.",
		"side"    : "This is where the woods and the path meet.",
		( { "woods", "forest" } ) : "The trees of the HavenWood "
					    "are tall and shady.",
		( { "trees", "tree" } ) : "These trees stand tall in the "
					  "forest.",
		( { "sand", "tan colored sand" } ) : "The tan colored sand "
						"has been blown around to "
						"cover the path.",
		"ground"  : "The ground here consists of the path.",
		( { "sea", "water", "eastern sea" } ) : "The eastern sea "
					"of Kailie is a dark blue and looks "
					"like rough water.",
		( { "waves", "large waves" } ) : "These large waves cover the "
						"water.",
		( { "shore", "beach" } ) : "The sand and the water of the sea "
					   "of the sea meet here to form "
					   "the beach.", 
		]) );
	SetExits( ([
		"north" : BEACH_ROOM "beach2",
		"east"  : BEACH_ROOM "beach6",
		"south" : BEACH_ROOM "beach4"
		]) );
}
