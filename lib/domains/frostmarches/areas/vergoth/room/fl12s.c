#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("twelfth floor room along the southern wall");
  SetLong("This room is a sleeping area for someone.  There is a single "
	"bed, a desk, and a chair here.  The bed is covered in fine blankets "
	"and lots of pillows that have been strewn across the room.  The "
	"desk has been destroyed and pieces of it are scattered across the "
	"room.  The chair is the only thing in this room that has been "
	"spared.  Someone was desperately trying to find something here.  "
	"There is a library to the northwest and a waiting area to the "
	"north.");
  SetItems( ([  ({"room","quarters"}) : "The room has been destroyed.",
	"bed" : "The bed has been completely destroyed.",
	"desk" : "The desk has been completely destroyed.",
	"chair" : "The chair is the only thing left intact in this "
		"room.  It is made from what appears to be spider webs and "
		"seems to be as strong as steel.",
	"library" : "The library is to the northwest.",
	({"wall", "walls","floor"}) : "The walls and floor are cut from a "
		"gray and very dull to look at stone. They glow very "
		"brightly from the inherant magic in the rocks.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	({"area"}) : "There is a waiting area to the north.",
	]) );
  SetItemAdjectives( ([ "area" : ({"guest","waiting"}),
	"wall" : ({"dull","stone","gray","glowing"}),
	"stone" : ({"gray","cut","smooth"}),
	"chair" : ({"spider","web"}),
	"desk" : ({"destroyed"}),
	"bed" : ({"destroyed"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "This room tingles with sound from the magic "
		"emanating from the walls." ]) );  
  SetSmell( ( [ "default" : "This room smells like the air after lightening "
		"hits the ground nearby." ]) );
  SetExits( ([ "northwest" : V_ROOM + "library",
	       "north" : V_ROOM + "fl12c" ]) );
}