/* This is the eighth room of the beach coded by Lynna on January 28, 1998
*/

#include <lib.h>
#include "../beach.h"
inherit LIB_ROOM;

static void create() {

	room::create();
	SetShort("the sand leading to the sea");
	SetClimate("temperate");
	SetSmell( ([ "default" : "The strong smell of the sea fills the "
				 "air." ]) );
	SetInventory( ([
		BEACH_NPC + "hermit" : 2,
		BEACH_NPC + "seagull" : 1,
		]) );
	SetListen( ([ "default" : "The crashing of the waves can be heard "
				  "but is muffled by the seagulls above." ]) );
	SetLong( "The sand here is hot, but grows colder as it gets closer "
		"to the cold waters. Birds can be seen flying "
		 "overhead. From here, the waves of the sea are visible and "
		 "are growing in size." );
	SetItems( ([
		"sand"   : "This is the light brown sand that lines the sea.",
		( { "waves", "waters", "sea", "water" } ) : "These are the "
						"dark blue waters of the "
						"eastern sea of Kailie.",
		( { "bird", "birds" } ) : "These small birds fly above the "
				          "waters of the eastern sea."
		]) );
	SetExits( ([
		"north" : BEACH_ROOM "beach7",
		"west"  : BEACH_ROOM "beach5",
		"east"  : BEACH_ROOM "beach10"
		]) );
}