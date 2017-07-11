#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("third floor stairs along the south wall");
  SetLong("The stairs seem to go on forever as they continue on up to the "
	"third floor.  They are very dull and carved from the same stone "
	"that the walls are made of and seem to be put together very "
	"skillfully.  The walls here are very bare and dull.  They lead up "
	"to the northeast and down to the northwest.");
  SetItems( ([ ({"wall", "walls","floor"}) : "The walls and floor are "
		"cut from a gray and very dull to look at stone.",
	({"staircase","stairs"}) : "The stairs are cut from a very "
		"dull and gray stone.  They are layered one on top of the "
		"other into an endless stretch.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	]) );
  SetItemAdjectives( ([ "wall" : ({"dull","stone","gray"}),
	"stairs" : ({"endless","dull","stone","layered"}),
	"stone" : ({"gray","cut","smooth"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The tower is very quiet." ]) );  
  SetSmell( ( [ "default" : "The tower smells moldy and stale." ]) );
  SetExits( ([ "northeast" : V_ROOM + "fl03e",
	       "northwest" : V_ROOM + "fl02w" ]) );
}