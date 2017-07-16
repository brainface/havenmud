/* This is the fourth room of the beach coded by Lynna on January 28, 1998
*/

#include <lib.h>
#include "../beach.h"
inherit LIB_ROOM;
static void create(){

	room::create();
	SetShort("the hot, smooth sand of the beach");
	SetLong("The sand of this beach is hot, but smooth. The sea is only "
		"a few feet away, with the waves crashing against the shore "
		"and the sand. In the sand, there are shells, stones, and "
		"and driftwood.");
	SetClimate("temperate");
	SetInventory( ([
		BEACH_NPC + "kid" : 1,
		BEACH_NPC + "hermit" : 1,
		]) );
	SetSmell( ([ "default" : "The salt of the sea is very stong in the "
				 "air." ]) );
	SetListen( ([ "default" : "The crashing of the waves and the squawking "
				  "of the seagulls are very loud here." ]) );
	SetItems( ([ 
		( { "sand", "hot smooth sand", "hot sand", "smooth sand" } ) : 
				"This is the hot smooth sand of the beach.",
		"beach"      : "This is the shore of the blue sea of Kailie.",
		( { "sea", "eastern sea" } ) : "The eastern sea of Kailie is "
						"dark and rough.",
		( { "waves", "large waves", "white waves", "large white "
		    "waves" } ) : "These large white waves cover the sea.",
		"shore"      : "The sand and the water of the sea meet here "
			       "to form the beach.",
		( { "shell", "shells" } ) : "These shells are small, but "
					    "beautiful.",
		( { "stones", "stone", "small stones" } ) : "These small "
					"are sharp and plentiful.",
		( { "bird", "birds" } ) : "These are the seagulls that fly "
					  "above the sea.",
		"driftwood"  : "This old worn wood is found all along the "
			       "shore.",
		( { "wood", "old wood", "worn wood", "old worn wood" } ) : 
							"This is the "
							"driftwood that "
							"is found along the "
							"beach.",
		( { "seagulls", "seagull" } ) : "These small, grey birds "
					       "hover above the sea."
		]) );
	SetExits( ([
		"north" : BEACH_ROOM "beach3",
		"east"  : BEACH_ROOM "beach5"
		]) );
}
