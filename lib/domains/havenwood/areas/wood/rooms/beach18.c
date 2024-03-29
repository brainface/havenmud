/* This is the eighteenth room of the beach coded by Lynna on January 28, 1998
*/

#include <lib.h>
#include "../beach.h"
inherit LIB_ROOM;
static void create() {

	room::create();
	SetShort("a path leading into the woods");
	SetClimate("temperate");
	SetInventory( ([
		BEACH_NPC + "squirrel" : 2,
		]) );
	SetSmell( ([ "default" : "The smells of the sea are mild and mixed "
				 "with the mild smells of the woods." ]) );
	SetListen( ([ "default" : "The crashing of the waves can be heard "
				  "softly in the distance." ]) );
	SetLong( "This point on the path leads directly to the sea to the "
		 "east, and to the west, the woods can be found. The tall "
		 "trees shade the long, narrow path, and the sand covers "
		 "the normally, dirt-covered trail." );
	SetItems( ([
		( { "path", "trail", "point" } ) : "This dirt path leads "
						   "around the woods by the "
						   "sea.",
		( { "waves", "sea" } ) : "This is the eastern sea of Kailie.",
		( { "woods", "trees", "tree" } ) : "These are the trees of "
						   "HavenWood.",
		"sand" : "This is the sand of the beach of the sea."
		]) );
	SetExits( ([
		"north"      : BEACH_ROOM "beach17",
		"west"       : BEACH_ROOM "beach21",
		"south"      : BEACH_ROOM "beach19",
		"southeast"  : BEACH_ROOM "beach13"
		]) );
}