/* This is the fifth room of the beach coded by Lynna on January 28, 1998
*/

#include <lib.h>
#include "../beach.h"
inherit LIB_ROOM;
static void create() {
	
	room::create();
	SetShort("the smooth sand of the beach");
	SetLong("The sand of this beach is hot, but smooth. The sea is only "
		"a few feet away, with the waves crashing against the shore "
		"and the sand. In the sand, there are shells, stones, and "
		"driftwood.");
	SetClimate("temperate");
	SetSmell( ([ "default" : "The strong smell of salt from the sea is "
				 "found in the air." ]) );
	SetListen( ([ "default" : "The noisy seagulls squawk much louder than "
				  "the crashing of the waves." ]) );
	SetInventory( ([
		BEACH_NPC + "duck" : 1,
		BEACH_OBJ + "shell" : 2,
		]) );
	SetItems( ([
		"sand"     : "The smooth, hot sand leads to the sea.",
		"beach"    : "The sand and the water of the sea form the "
			     "long, beautiful beach.",
		( { "water", "sea" } ) : "The eastern sea of Kailie is dark "
					 "and rough here.",
		"waves"    : "These waves are large and white-capped.",
		"shore"    : "This is where the sand and the water of the "
			     "sea meet.",
		( { "shells", "shell" } ) : "These shells are small and "
					    "beautiful.",
		( { "stones", "stone" } ) : "These small stones cover the "
					    "sand of the shore.",
		"driftwood": "This withered wood can be found near the shore "
			     "of the sea.",
		"wood"     : "This driftwood lies on the surface of the "
			     "beach.",
		"salt"     : "The salt of the sea can not be seen.",
		"air"      : "The air is full of the salty sea smell.",
		"seagulls" : "These birds fly high above landing on the "
			     "surface of the water occasionally.",
		( { "bird", "birds" } ) : "These are the seagulls that "
				          "fly high in the sky."
		]) );
	SetExits( ([
		"west"  : BEACH_ROOM "beach4",
		"east"  : BEACH_ROOM "beach8",
		"north" : BEACH_ROOM "beach6"
		]) );
}
