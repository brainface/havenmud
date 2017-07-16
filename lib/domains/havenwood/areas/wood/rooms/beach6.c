/* This is the sixth room of the beach coded by Lynna on January 28, 1998
*/

#include <lib.h>
#include "../beach.h"
inherit LIB_ROOM;
static void create() {

	room::create();
	SetShort("a path that lies along the beach");
	SetSmell( ([ "default" : "The strong smell of the salty sea fills "
			         "the air." ]) );
	SetLong("This path leading from the woods is long and narrow.  Along "
		"the side of the dirt-covered path, the sand has started to "
		"cover the ground. The sea can be seen from this point on "
		"the path, and it is only a short walk to the water.");
	SetClimate("temperate");
	SetListen( ([ "default" : "The crashing of the waves along the shore "
			          "be heard." ]) );
	SetInventory( ([
		BEACH_OBJ + "rock" : 1,
		]) );
	SetItems( ([
		( { "path", "point" } ) : "This path is long and narrow, "
				          "leading to the woods.",
		"side"      : "This is where the woods meet the path.",
		( { "trees", "tree", "woods" } ) : "These woods are large and "
						   "dark.",
		"sand"     : "This sand is part of the shore of the sea.",
		"shore"    : "This is where the sand and the water of the "
			     "sea meet.",
		"ground"   : "The ground is the dirt-covered path.",
		"sea"      : "The eastern sea of Kailie is dark and rough.",
		"water"    : "The water here is deep blue.",
		( { "waves", "wave" } ) : "These tall white-capped waves "
					  "cover the dark blue sea.",
		( { "birds", "bird" } ) : "These are the small seagulls that "
				          "fly high above.",
	   	( { "seagulls", "seagull" } ) : "These small birds fly above "
						"making lots of noise.",
		]) );
	SetExits( ([
		"south" : BEACH_ROOM "beach5",
		"west"  : BEACH_ROOM "beach3",
		"east"  : BEACH_ROOM "beach7"
		]) );
}
