/* This is the seventh room of the beach coded by Lynna on January 28, 1998
*/

#include <lib.h>
#include "../beach.h"
inherit LIB_ROOM;
static void create() {

	room::create();
	SetShort("a path that lies along the beach");
	SetClimate("temperate");
	SetInventory( ([
		BEACH_NPC + "squirrel" : 1,
		]) );
	SetLong ( "This path that leads to the beach is long and narrow. It "
		  "lies between the woods and the sandy beach. The trees of "
		  "the woods shade the path. In the distance, the path "
		  "begins to stretch back to the HavenWood.");
	SetSmell( ([ "default" : "The strong, salty smell of the sea fills "
				 "the air." ]) );
	SetListen( ([ "default" : "The soothing crashing of the waves can "
				  "be heard from here." ]) );
	SetItems( ([
		"path"     : "This path leads around the wood and passes by "
			     "the sandy beach.",
		( { "beach", "sandy beach", "sand" } ) : "The sand and the "
						"waters of the sea meet here "
						"to form the beach.",
		( { "woods", "trees", "tree" } ) : "These are the tall trees "
						   "of the HavenWood.",
		"sea"      : "The eastern sea of Kailie is dark and rough.",
		"waves"    : "These tall white-capped waves cover the "
			     "dark blue sea.",
		"shore"   : "This is the sand that lies again the water "
			    "of the eastern sea.",
				  ]) );
	SetExits( ([
		"west" : BEACH_ROOM "beach6",
		"south": BEACH_ROOM "beach8",
		"east" : BEACH_ROOM "beach9"
		]) );
}