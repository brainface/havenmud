#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("first floor stairs along the north wall");
  SetLong("This is the begining of a very long flight of stairs that "
	"seems to lead all the way to the heavens.  The stairs are "
	"very dull and carved from the same stone that the walls are "
	"made of and seem to be put together by skilled hands.  There "
	"is a single painting on the wall here.  The stairs continue "
	"southwest going up and southeast going down.");
  SetItems( ([ 
	({"wall", "walls","floor"}) : "The walls and floor are cut from a "
		"gray and very dull to look at stone.",
	({"staircase","stairs"}) : "The stairs are cut from a very "
		"dull and gray stone.  They are layered one on top of the "
		"other into an endless stretch.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	"painting" : "The painting is of a very young gentleman, possibly "
		"the owner of the tower or a relative.  He is very nice and "
		"gentle looking." ]) );
  SetItemAdjectives( ([ "stairs" : ({"endless","dull","stone","layered"}),
	"wall" : ({"dull","gray","stone"}),
	"painting" : ({"wall"}),
	"stone" : ({"gray","cut","smooth"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The staircase is very quiet." ]) );  
  SetSmell( ( [ "default" : "The staircase smells of fresh air." ]) );
  SetExits( ([ "southwest" : V_ROOM + "fl01w",
	       "southeast" : V_ROOM + "fl01e" ]) );
}