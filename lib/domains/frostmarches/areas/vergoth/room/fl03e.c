#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("third floor stairs along the east wall");
  SetLong("The stairs continue up to another level.  The stairs are "
	"very dull and carved from the same stone that the walls are "
	"made of and seem to be put together by skilled hands.  There isn't "
	"anything here to distinguish this part of the tower from "
	"the floor below it.  The stairs lead up to the northwest and "
	"down to the southwest.  To the west there appear to be "
	"some sleeping rooms.");
  SetItems( ([ "room" : "There guest rooms off to the west",
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
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The staircase is very quiet." ]) );  
  SetSmell( ( [ "default" : "The staircase smells very slightly of fresh air." ]) );
  SetExits( ([ "northwest" : V_ROOM + "fl03n",
               "west" : V_ROOM + "guestqtr",
	       "southwest" : V_ROOM + "fl03s" ]) );
}