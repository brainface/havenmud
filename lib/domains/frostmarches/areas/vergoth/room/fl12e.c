#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("twelfth floor entry along the east wall");
  SetLong("This is the top of the tower.  This room is very sparse, other "
	"than the stairs there is nothing here but an entry to the next "
	"room.  The walls and the floor are all cut from a gray stone.  The "
	"room is lit up very brightly by the emanations given off by the "
	"rocks and the air tingles with all the magic in the air.  Leading "
	"down is a staircase while leading west is a guest area.");
  SetItems( ([  ({"tower","level"}) : "This is the top of the tower.",
	"room" : "The room is bare other then the entry to "
		"the guest area and the staircase going down.",
	({"stairs","staircase"}) : "The stairs return down the "
		"tower.",
	({"wall", "walls","floor"}) : "The walls and floor are cut from a "
		"gray and very dull to look at stone. They glow very "
		"brightly from the inherant magic in the rocks.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	"area" : "The guest area is very decorated and comfortable.",
	]) );
  SetItemAdjectives( ([  "wall" : ({"dull","stone","gray","glowing"}),
	"stairs" : ({"endless","dull","stone","layered"}),
	"stone" : ({"gray","cut","smooth"}),
	"area" : ({"guest"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "This room tingles with sound from the magic "
		"emanating from the walls." ]) );  
  SetSmell( ( [ "default" : "This room smells like the air after lightning "
		"hits the ground nearby." ]) );
  SetExits( ([ "down" : V_ROOM + "fl11c",
	       "west" : V_ROOM + "fl12c" ]) );
}