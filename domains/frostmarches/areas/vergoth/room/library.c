#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("twelfth floor library along the western wall");
  SetLong("This room appears to have been a library at some point.  The "
	"books here are strewn all about the floor and some of the shelves "
	"have been knocked down.  It seems as though someone was desperatly "
	"searching for something.  There is a lab to the northeast, a room "
	"to the southeast, and a waiting area is off to the east.");
  SetItems( ([  "library" : "The library is in a terrible state.  There are "
		"books scattered everywhere and the shelves are knocked "
		"over.",
	({"book","books"}) : "The books have been strewn all about the room "
		"and are destroyed.  The shelves have been knocked over on "
		"top of the books",
	({"shelf","shelve","shelves"}) : "The shelves are carved from "
		"the same gray stone as the walls are.  They are very tall"
		"and very heavy, preventing anyone from looking at the "
		"scattered books underneath them.",
	({"wall", "walls","floor"}) : "The walls and floor are cut from a "
		"gray and very dull to look at stone. They glow very "
		"brightly from the inherant magic in the rocks.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and is a light gray in color.",
	({"lab"}) : "There is a lab to the northeast.",
	({"room"}) : "There is a room to the southeast.",
	({"area"}) : "There is a waiting area to the east.",
	]) );
  SetItemAdjectives( ([ "area" : ({"waiting"}),
	"wall" : ({"dull","stone","gray","glowing"}),
	"stone" : ({"gray","cut","smooth"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "This room tingles with sound from the magic "
		"emanating from the walls." ]) );  
  SetSmell( ( [ "default" : "This room smells like the air after lightening "
		"hits the ground nearby." ]) );
  SetExits( ([ "southeast" : V_ROOM + "fl12s",
	       "northeast" : V_ROOM + "lab",
	       "east" : V_ROOM + "fl12c" ]) );
}