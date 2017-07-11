#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("second floor stairs along the west wall");
  SetLong("The stairs continue up into a third floor.  They are very "
	"dull and carved from the same stone that the walls are made of "
	"and seem to be put together very skillfully.  There is a "
	"painting on the wall here.  The stairs continue southeast "
	"going up and northeast going down.");
  SetItems( ([ ({"wall", "walls","floor"}) : "The walls and floor are "
		"cut from a gray and very dull to look at stone.",
	({"staircase","stairs"}) : "The stairs are cut from a very "
		"dull and gray stone.  They are layered one on top of the "
		"other into an endless stretch.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	"painting" : "The painting is of a small pond.  There are trees "
		"along the far shoreline and a boat in the center of the "
		"pond.  A young women waves to a man on the boat.",
	]) );
  SetItemAdjectives( ([ "wall" : ({"dull","stone","gray"}),
	"stairs" : ({"endless","dull","stone","layered"}),
	"stone" : ({"gray","cut","smooth"}),
	"painting" : ({"wall"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The staircase is very quiet." ]) );  
  SetSmell( ( [ "default" : "The stairs smell of dust and decay." ]) );
  SetExits( ([ "southeast" : V_ROOM + "fl03s",
	       "northeast" : V_ROOM + "fl02n" ]) );
}