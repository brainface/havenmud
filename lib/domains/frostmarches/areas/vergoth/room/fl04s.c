#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("fourth floor stairs along the south wall");
  SetLong("The stairs continue up into a fifth floor.  They are very "
	"dull and carved from the same stone that the walls are made of "
	"and seem to be put together very skillfully.  The stairs lead "
	"up to the northeast and down to the northwest.  The walls here "
	"are bare other than a small window looking out to the world.");
  SetItems( ([ ({"wall", "walls","floor"}) : "The walls and floor are "
		"cut from a gray and very dull to look at stone.",
	({"staircase","stairs"}) : "The stairs are cut from a very "
		"dull and gray stone.  They are layered one on top of the "
		"other into an endless stretch.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	"window" : "This small window is barely large enough to see Kailie.  "
		"However looking out, the view is blocked by the tops of the trees.", 
	]) );
  SetItemAdjectives( ([ "wall" : ({"dull","stone","gray"}),
	"stairs" : ({"endless","dull","stone","layered"}),
	"stone" : ({"gray","cut","smooth"}),
	"window" : ({"small"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The wind whistles through the staircase." ]) );  
  SetSmell( ( [ "default" : "The staircase smells of fresh air." ]) );
  SetExits( ([ "northeast" : V_ROOM + "fl04e",
	       "northwest" : V_ROOM + "fl03w" ]) );
}