#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("third floor stairs along the north wall");
  SetLong("The stairs continue on up to a fourth floor.  The stairs "
	"do not change much and appear to be carved from the same "
	"stone that the walls are made of.  There isn't anything in "
        "this part of the staircase to seperate it from any other "
	"part.  They wind around and lead up to the southwest and back "
	"down to the third level to the southeast.");
  SetItems( ([ ({"wall", "walls","floor"}) : "The walls and floor are cut "
		"from a gray and very dull to look at stone.",
	({"staircase","stairs"}) : "The stairs are cut from a very "
		"dull and gray stone.  They are layered one on top of the "
		"other into an endless stretch.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	]) );
  SetItemAdjectives( ([ "stairs" : ({"endless","dull","stone","layered"}),
	"wall" : ({"dull","gray","stone"}),
	"stone" : ({"gray","cut","smooth"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The staircase is very quiet." ]) );  
  SetSmell( ( [ "default" : "The stairs smell of fresh air." ]) );
  SetExits( ([ "southwest" : V_ROOM + "fl03w",
	       "southeast" : V_ROOM + "fl03e" ]) );
}