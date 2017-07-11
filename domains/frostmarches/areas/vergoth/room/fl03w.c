#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("third floor stairs along the west wall");
  SetLong("The stairs continue up into a second floor.  They are very "
	"dull and carved from the same stone that the walls are made of "
	"and seem to be put together very skillfully.  There is a "
	"painting on the wall here.  The stairs "
	"continue southeast going up and northeast going down.");
  SetItems( ([ ({"wall", "walls","floor"}) : "The walls and floor are "
		"cut from a gray and very dull to look at stone.",
	({"staircase","stairs"}) : "The stairs are cut from a very "
		"dull and gray stone.  They are layered one on top of the "
		"other into an endless stretch.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	"painting" : "This painting is different from the others so far. "
		"It is a little more disturbing as it is a painting "
		"of a man who has been stabbed by a dagger.",
	]) );
  SetItemAdjectives( ([ "wall" : ({"dull","stone","gray"}),
	"stairs" : ({"endless","dull","stone","layered"}),
	"stone" : ({"gray","cut","smooth"}),
	"painting" : ({"wall"}),
	]) );
  SetInventory( ([
	V_NPC + "rat" : 1,
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "A slight wind whistles through the staircase." ]) );  
  SetSmell( ( [ "default" : "The staircase smells of very fresh air." ]) );
  SetExits( ([ "southeast" : V_ROOM + "fl04s",
	       "northeast" : V_ROOM + "fl03n" ]) );
}