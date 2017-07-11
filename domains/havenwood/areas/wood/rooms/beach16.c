/* This is the sixteenth room of the beach coded by Lynna on January 28, 1998
*/

#include <lib.h>
#include "../beach.h"
inherit LIB_ROOM;
static void create() {

	room::create();
	SetShort("a cool patch of sand");
	SetClimate("temperate");
	SetSmell( ([ "default" : "The smell of the sea is mild mixed with "
			         "the smells of the woods." ]) );
	SetListen( ([ "default" : "The sounds of the sea can be heard in the "
				  "distance." ]) );
	SetInventory( ([	
		BEACH_NPC + "turtle" : 1,
		]) );
	SetLong( "This cool patch of shaded sand sits next to the path, and "
		 "receives its shade from the tall trees that lie behind it. "
		 "From this point, the sea can be seen. The birds that fly "
		 "above the sea are only dots in the sky." );
	SetItems( ([
		"sand" : "The smooth sand here leads to the sea.",
		"path" : "This long, narrow path leads through the woods.",
		"sea"  : "The eastern sea is dark, blue, and very rough.",
		( { "woods", "trees", "tree" } ) : "The trees of the "
						   "HavenWood are tall and "
						   "dark.",
		"patch": "This is a cool patch of shaded sand.",
		( { "seagull", "seagulls" } ) : "These birds fly high above "
						"the sea.",
		( { "birds", "bird" } ) : "These are the seagulls that fly "
					  "above the sea.",
		]) );
	SetExits( ([
		"east" : BEACH_ROOM "beach15",
		"west" : BEACH_ROOM "beach17"
		]) );
}