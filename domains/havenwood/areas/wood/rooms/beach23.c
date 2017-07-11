/* This is the twenty-third room of the beach coded by Lynna on 
		January 28, 1998
*/

#include <lib.h>
#include "../beach.h"
inherit LIB_ROOM;
static void create() {

	room::create();
	SetShort("the woods");
	SetSmell( ([ "default" : "The smell here is plainly of fresh air." 
				 ]) );
	SetListen( ([ "default" : "The rustling of the leaves in the trees "
				  "above is loud, but soothing." ]) );
	SetInventory( ([
		BEACH_NPC + "chipmunk" : 1,
		]) );
	SetLong( "From this part of the woods, the beginning of the trail "
		 "can be seen towards the west. Towards the south, the edge "
		 "of the woods can be found. The trees here are tall, but "
		 "not as tall as those found towards the center of the "
		 "woods.");
	SetItems( ([
		( { "woods", "trees", "tree" } ) : "These are the tall shady "
						   "trees of the HavenWood.",
		"edge" : "The trees here line the path that follows around "
			 "woods and past the sea.",
		( { "leaves", "leaf" } ) : "The leaves are high up in the "
					   "trees.",
		"trail"  : "This trail leads around the woods and past the "
			   "sea.",
		"sea"    : "The eastern sea of Kailie is dark and rough.",
		]) );
	SetClimate("temperate");
	SetExits( ([
		"northeast" : BEACH_ROOM "beach22",
		"west"      : BEACH_ROOM "beach1",
		"south"     : BEACH_ROOM "beach24"
		]) );
}