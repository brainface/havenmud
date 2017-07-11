/* This is the twentieth room of the beach coded by Lynna on January 28, 1998
*/

#include <lib.h>
#include "../beach.h"
inherit LIB_ROOM;
static void create() {
	
	room::create();
	SetShort("near the HavenWood");
	SetClimate("temperate");
	SetSmell( ([ "default" : "The strong smell of the woods overpowers "
				 "the now mild scents of the sea." ]) );
	SetListen( ([ "default" : "The crashing of the waves on the shore "
				  "can be heard in the distance." ]) );
	SetLong( "This part of the woods lies next to the path, and by "
		 "looking towards the southwest, the deep blue sea can be "
		 "seen. The trees here are tall and shade the path that "
		 "surrounds these woods." );
	SetItems( ([
		( { "trees", "tree", "woods" } ) : "These are the tall trees "
						   "of the HavenWood.",
		( { "sea", "waves" } ) : "This is the eastern sea of Kailie.",
		"path" : "This path leads around the woods.",
		"shore": "This is the shore of the eastern sea."
		]) );
	SetExits( ([
		"west" : BEACH_ROOM "beach24",
		"north": BEACH_ROOM "beach21",
		"east" : BEACH_ROOM "beach19"
		]) );
}