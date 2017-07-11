#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("fourth floor stairs along the east wall");
  SetLong("The stairs continue up to another level.  The stairs are "
	"very dull and carved from the same stone that the walls are "
	"made of and seem to be put together by skilled hands.  Along "
	"the east wall is a statue of a woman.  The stairs lead up to "
	"the northwest and down to the southwest.  To the west there "
	"appears to be a small kitchen.");
  SetItems( ([ "statue" : "The statue is of a very pretty woman.  It is very "
		"expertly carved from a very exotic looking dark wood.",
	"kitchen" : "There is a kitchen off to the west.",
	"wood" : "The wood appears to be from another land.  The grain is "
		"very tight in the wood and appears to be very strong.",
	({ "wall", "walls", "stone" }) : "The walls and floor are cut from a "
		"gray and very dull to look at stone.",
	({ "stairs", "staircase" }) : "The stairs are cut from a very "
		"dull and gray stone.  They are layered one on top of the "
		"other into an endless stretch.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	]) );
  SetItemAdjectives( ([ "room" : ({"guest","sleeping"}),
	"wall" : ({"dull","gray","stone"}),
	"stone" : ({"gray","cut","smooth"}),
	"wood" : ({"exotic","dark"}),
	"statue" : ({"wood","woman","exotic","pretty"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The staircase is very quiet." ]) );  
  SetSmell( ( [ "default" : "The staircase smells slightly of food." ]) );
  SetExits( ([ "northwest" : V_ROOM + "fl04n",
               "west" : V_ROOM + "kitchen",
	       "southwest" : V_ROOM + "fl04s" ]) );
}