#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("second floor stairs along the east wall");
  SetLong("The stairs continue up to another level.  The stairs are "
	"very dull and carved from the same stone that the walls are "
	"made of and seem to be put together by skilled hands.  Along the "
	"east wall is a vase.  The stairs lead up to the northwest "
	"and down to the southwest.  To the west is a small den.");
  SetItems( ([ "vase" : "The vase is small and is sitting on a table along "
		"the east wall.  It is made of a white porcelain and stands "
		"about twelve inches high.  There is a mural of some tiny "
		"village on it.",
	"table" : "The table is carved of wood and stained a very dark "
		"brown.  It stands about four feet high, has three legs "
		"supporting it, and a large round top.",
	"den" : "There is a den off to the west",
	({ "wall", "walls", "stone" }) : "The walls and floor are cut from a "
		"gray and very dull to look at stone.",
	({ "stairs", "staircase" }) : "The stairs are cut from a very "
		"dull and gray stone.  They are layered one on top of the "
		"other into an endless stretch.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	]) );
  SetItemAdjectives( ([ "table" : ({"wood","dark"}),
	"vase" : ({"small","porcelin"}),
	"wall" : ({"dull","gray","stone"}),
	"stone" : ({"gray","cut","smooth"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The air whistles through the staircase." ]) );  
  SetSmell( ( [ "default" : "The air here smells fresh." ]) );
  SetExits( ([ "northwest" : V_ROOM + "fl02n",
               "west" : V_ROOM + "den",
	       "southwest" : V_ROOM + "fl02s" ]) );
}