/* This is the ninth room of the beach coded by Lynna on January 28, 1998
*/

#include <lib.h>
#include "../beach.h"
inherit LIB_ROOM;
static void create() {

	room::create();
	SetShort("a path along the beach");
	SetListen( ([ "default" : "The crashing of the waves along the shore "
				  "and the seagulls can be heard." ]) );
	SetSmell( ([ "default"  : "The strong salty smell of the sea fills "
				  "the air." ]) );
	SetLong( "This path now begins to bend back towards the woods and "
		 "away from the sandy beach. The trees still line the path, "
		 "but from this point, the beach can be seen clearly." ); 
	SetClimate("temperate");
	SetItems( ([
		( { "point", "path" } ) : "This path leads around the woods "
					  "and past the beach.",
		( { "beach", "shore", "sandy beach" } ) : "The sand and the "
					"waters of the sea can be seen from "
					"here.",
	   	( { "water", "waters", "sea" } )  : "The eastern sea of "
					            "Kailie is dark blue and "
					            "rough.",
		( { "seagull", "seagulls" } )     : "These birds fly above "
					"the sea and land occasionally.",
		( { "birds", "bird" } ) : "These small seagulls fly high "
					"above the sea.",
		( { "woods", "tree", "trees" } ) : "The trees of the "
						   "HavenWood are tall and "
						   "ominous.",
		]) );
	SetInventory( ([
		BEACH_OBJ + "sign" : 1,
		]) );
	SetExits( ([
		"west"      : BEACH_ROOM "beach7",
		"north" : BEACH_ROOM "beach19"
		]) );
}
