#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("fourth floor stairs along the west wall");
  SetLong("The stairs continue up into a second floor.  They are very "
	"dull and carved from the same stone that the walls are made of "
	"and seem to be put together very skillfully.  There is a "
	"painting on the wall here.  The stairs continue southeast "
	"going up and northeast going down.");
  SetItems( ([ ({"wall", "walls","floor"}) : "The walls and floor are "
		"cut from a gray and very dull to look at stone.",
	({"staircase","stairs"}) : "The stairs are cut from a very "
		"dull and gray stone.  They are layered one on top of the "
		"other into an endless stretch.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	"painting" : "The paintings seem to get more disturbing as the "
		"top of the tower grows nearer.  This painting is of "
		"a woman being burned at the stake.  It is painted so "
		"well that her pain can be felt as the flames lick at "
		"body and burn.",
	]) );
  SetItemAdjectives( ([ "wall" : ({"dull","stone","gray"}),
	"stairs" : ({"dull","stone","layered"}),
	"stone" : ({"gray","cut","smooth"}),
	"painting" : ({"disturbing"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The wind whistles through the staircase." ]) );  
  SetSmell( ( [ "default" : "The air smells very fresh here." ]) );
  SetExits( ([ "southeast" : V_ROOM + "fl05s",
	       "west" : V_ROOM + "wt1",
	       "northeast" : V_ROOM + "fl04n" ]) );
}