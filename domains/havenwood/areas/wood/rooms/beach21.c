/* This is the twenty-first room of the beach coded by Lynna 
	on January 28, 1998
*/

#include <lib.h>
#include "../beach.h"
inherit LIB_ROOM;
static void create() {
	room::create();
	SetShort( "near the HavenWood" );
	SetSmell( ([ "default" : "The strong smell of the woods overpowers "
				 "the now mild scents of the sea." ]) );
	SetInventory( ([
		BEACH_OBJ + "rock" : 2,
		]) );
	SetListen( ([ "default" : "The crashing of the waves of the sea can "
				  "be heard in the distance." ]) );
	SetLong( "The woods here are dark, but are close enough to the path "
		 "that the light can be seen through the trees. The trees " 
		 "line the dirt path that surrounds this part of the woods."
		 );
	SetItems( ([
		( { "woods", "trees", "tree" } ) : "These are the tall trees "
						   "of the HavenWood.",
		( { "sea", "waves" } ) : "This is the eastern sea of Kailie.",
		"path" : "This path leads around the woods near the sea."
		]) );
	SetClimate("temperate");
	SetExits( ([
		"east" : BEACH_ROOM "beach18",
		"south": BEACH_ROOM "beach20", 
		"north": BEACH_ROOM "beach22"
		]) );
}