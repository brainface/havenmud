#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("fifth floor stairs along the west wall");
  SetLong("The stairs continue up into a second floor.  They are very "
	"dull and carved from the same stone that the walls are made of "
	"and seem to be put together very skillfully.  There is a "
	"painting on the wall here.  The stairs lead up to the "
	"southeast and down to the northeast.");
  SetItems( ([ ({"wall", "walls","floor"}) : "The walls and floor are "
		"cut from a gray and very dull to look at stone.",
	({"staircase","stairs"}) : "The stairs are cut from a very "
		"dull and gray stone.  They are layered one on top of the "
		"other into an endless stretch.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	"painting" : "The paintings seem to get even more disturbing the "
		"higher in the tower they are.  This painting is of a "
		"young man holding a bloody knife over the body of a "
		"woman as he is struck by lightning.",
	]) );
  SetItemAdjectives( ([ "wall" : ({"dull","stone","gray"}),
	"stairs" : ({"endless","dull","stone","layered"}),
	"stone" : ({"gray","cut","smooth"}),
	"painting" : ({"wall"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "A slight wind whistles through the staircase." ]) );  
  SetSmell( ( [ "default" : "The staircase smells of very fresh air." ]) );
  SetExits( ([ "southeast" : V_ROOM + "fl06s",
	       "northeast" : V_ROOM + "fl05n" ]) );
}