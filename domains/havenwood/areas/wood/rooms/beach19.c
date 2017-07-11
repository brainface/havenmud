/* This is the nineteenth room of the beach coded by Lynna on January 28, 1998
*/

#include <lib.h>
#include "../beach.h"
inherit LIB_ROOM;
static void create() {

	room::create();
	SetShort("a path leading from the beach to the woods");
	SetSmell( ([ "default" : "The smell of the salty sea is mild." ]) );
	SetListen( ([ "default" : "The crashing of the waves on the shore "
				  "can be heard in the distance." ]) );
	SetInventory( ([
		BEACH_NPC + "squirrel" : 1,
		BEACH_NPC + "chipmunk" : 1,
		]) );
	SetLong( "This long, narrow path continues around the trees of the "
		 "HavenWood, bending at a point where the sea is clearly "
  		 "visible. The trees grow tall overhead and shade the "
		 "dirt-covered trail." );
	SetItems( ([
		( { "path", "trail" } ) : "This path leads around the woods.",
		( { "beach", "shore" } ) : "This is the shore of the sea.",
		( { "woods", "trees", "tree" } ) : "These are the trees of "
						   "the HavenWood.",
		( { "waves", "sea" } ) : "This is the eastern sea of Kailie.", 
		]) );
	SetClimate("temperate");
	SetExits( ([
		"north"     : BEACH_ROOM "beach18",
		"south"     : BEACH_ROOM "beach9",
		"west"      : BEACH_ROOM "beach20"
		]) );
}
