#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("sixth floor stairs along the east wall");
  SetLong("The stairs continue up to another level.  The stairs are "
	"very dull and carved from the same stone that the walls are "
	"made of and seem to be put together by skilled hands.  Along the "
	"east wall is a statue of a dragon.  The stairs leading northwest "
	"go up and southwest going down.");
  SetItems( ([ "statue" : "The statue is of a dragon.  It is carved from "
		"some unknown material and looks very lifelike, as though "
		"it might move at any moment.  It is painted in a dark red "
		"and the scales are painted in great detail.  It's jaw is "
		"wide open as if it is about to eat or breathe out a hot "
		"fire to consume any onlookers.",
	({ "wall", "walls", "stone" }) : "The walls and floor are cut from a "
		"gray and very dull to look at stone.",
	({ "stairs", "staircase" }) : "The stairs are cut from a very "
		"dull and gray stone.  They are layered one on top of the "
		"other into an endless stretch.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	]) );
  SetItemAdjectives( ([ "statue" : ({"dragon"}),
	"wall" : ({"dull","gray","stone"}),
	"stone" : ({"gray","cut","smooth"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The wind whistles slightly through the staircase." ]) );  
  SetSmell( ( [ "default" : "The staircase smells only of fresh air." ]) );
  SetExits( ([ "northwest" : V_ROOM + "fl06n",
	       "southwest" : V_ROOM + "fl06s" ]) );
}