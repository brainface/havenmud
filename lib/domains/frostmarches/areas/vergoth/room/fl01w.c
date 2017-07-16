#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("first floor stairs along the west wall");
  SetLong("The stairs continue up into a second floor.  They are very "
	"dull and carved from the same stone that the walls are made of "
	"and seem to be put together very skillfully.  There is a small "
	"statue on a pedestal here.  The stairs lead up to the southeast "
	"down to the northeast.");
  SetItems( ([ ({"wall", "walls","floor"}) : "The walls and floor are "
		"cut from a gray and very dull to look at stone.",
	({"staircase","stairs"}) : "The stairs are cut from a very "
		"dull and gray stone.  They are layered one on top of the "
		"other into an endless stretch.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	"statue" : "The statue is a bust of someone's head.  The person "
		"that the statue represents is an older gentleman with gentle "
		"features.",
	"pedastel" : "The pedestal is a single piece of nicely carved "
		"oak.  It is round and stands hugh enough to keep the "
		"statue at eyelevel.  It is stained a light brown color.",
	 ]) );
  SetItemAdjectives( ([ "wall" : ({"dull","stone","gray"}),
	"stairs" : ({"endless","dull","stone","layered"}),
	"stone" : ({"gray","cut","smooth"}),
	"statue" : ({"small"}),
	"pedastool" : ({"single","oak","stained","brown"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "From this part of the stairs there is a "
	"slight wind." ]) );  
  SetSmell( ( [ "default" : "The air here smells very fresh." ]) );
  SetExits( ([ "southeast" : V_ROOM + "fl02s",
	       "northeast" : V_ROOM + "fl01n" ]) );
}