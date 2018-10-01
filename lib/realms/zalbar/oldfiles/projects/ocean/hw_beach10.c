/* This is the tenth room of the beach coded by Lynna on January 28, 1998
*/
#include <lib.h>
#include <domains.h>
#include "../beach.h"
inherit LIB_FISHING;
static void create() {

	fishing::create();
	SetShort("the shallow waters of the sea");
	SetSmell( ([ "default" : "The strong smell of salt is strong this "
				 "close to the water." ]) );
	SetListen( ([ "default" : "While standing in the shallow water, "
				  "the splashing of the fish can be heard." 
				  ]) );
	SetInventory( ([
		BEACH_NPC + "fisherman" : 1,
		BEACH_NPC + "fish"      : 3,
		]) );
	SetLong( "The water here is cold, and the depths of the sea ahead "
		 "look dark and colder. The seagulls fly overhead, and the "
		"animals of the sea swim throghout the waters below." );
	SetItems( ([
		( { "waters", "water", "sea" } ) : "These are the rough "
						   "waters of the eastern "
						   "sea of Kailie.",
		"salt" : "The salt is not visible in this water.",
		"waves" : "These large white-capped waves cover the sea.",
		( { "fish", "fishes" } ) : "The tiny fish swim throughout "
					   "the water.",
		( { "seagulls", "seagull" } )  : "These birds fly above the "
						 "sea.",
		( { "birds", "bird" } ) : "These are the seagulls that fly "
				          "in the sky.",
		]) );
	SetClimate("temperate");
	SetExits( ([
		"west"  : BEACH_ROOM "beach8",
		"east"  : BEACH_ROOM "beach11",
		"south" : INNERSEA_VIRTUAL "ocean/9,33",
		]) );
	SetSpeed(5);
	SetFish( ([
		"/std/fish/guppy" : 100,
		"/std/fish/shark" : 10,
		]) );
	SetChance(25);
	SetMaxFishing(12);
}
