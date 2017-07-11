#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("fifth floor stairs along the south wall");
  SetLong("The stairs seem to go on forever as they continue on up "
	"to the fifth floor.  They are very dull and carved from the "
	"same stone that the walls are made of and seem to be put "
	"together very skillfully.  On the southern wall is a candlebra."
	"  It is made from brass and set to hold three candles.  The "
	"three it holds are all melted down.  Northeast leads up and "
	"northwest leads down.");
  SetItems( ([ ({"wall", "walls","floor"}) : "The walls and floor are "
		"cut from a gray and very dull to look at stone.",
	({"staircase","stairs"}) : "The stairs are cut from a very "
		"dull and gray stone.  They are layered one on top of the "
		"other into an endless stretch.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	"candlebra" : "The candlebra is made from brass that has dulled "
		"through the ages.  The three candles it will hold are "
		"melted all the way down to nubs.." 
	]) );
  SetItemAdjectives( ([ "wall" : ({"dull","gray","stone"}),
	"stairs" : ({"endless","dull","stone","layered"}),
	"stone" : ({"gray","cut","smooth"}),
	"floor" : ({"fifth"}),
	"candlebra" : ({"brass"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The staircase is very quiet." ]) );  
  SetSmell( ( [ "default" : "The staircase smells slightly of fresh air." ]) );
  SetExits( ([ "northeast" : V_ROOM + "fl05e",
	       "northwest" : V_ROOM + "fl04w" ]) );
}