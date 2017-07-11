#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("twelfth floor lab along the northern wall");
  SetLong("There are tables covered in papers that have been messed up.  "
	"It looks as though someone has been digging through here trying to "
	"find something.  There are vials and beakers broken all over the "
	"floor and a variety of strange smelling stuff has been spilled on "
	"the floor.  There is a library to the southwest and the waiting "
	"room is south.");
  SetItems( ([  ({"vial","vials","beaker","beakers","item","items"}) :
		"Everything in this room appears to be broken or destroyed "
		"in someone's attempt to find something.",
	({"wall", "walls","floor"}) : "The walls and floor are cut from a "
		"gray and very dull to look at stone. They glow very "
		"brightly from the inherant magic in the rocks.",
	({"paper","papers"}) : "All the papers have been destroyed "
		"by the funny smelling liquid scattered from all the vials.",
	"glass" : "There is shattered glass all over the floor.",
	"stuff" : "There is a strange mix of liquids on the ground.",
	"library" : "The library looks large from here.",
	"room" : "The waiting room looks very comfortable.",
	({"table","tables"}) : "The tables in this room are carved from stone "
		"and are very heavy.  They have been tipped over and pieces "
		"of them have broken off.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	]) );
  SetItemAdjectives( ([ "stuff" : ({"funny","smelling"}),
	"glass" : ({"shattered"}),
	"room" : ({"waiting"}),
	"wall" : ({"dull","stone","gray","glowing"}),
	"stone" : ({"gray","cut","smooth"}),
	"liquid" : ({"strange"}),
	"table" : ({"stone","broken"}),
	"vial" : ({"broken"}),
	"beaker" : ({"broken"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetListen( ([ "default" : "This room tingles with sound from the magic "
		"emanating from the walls." ]) );  
  SetSmell( ( [ "default" : "This room smells like the air after lightening "
		"hits the ground nearby." ]) );
  SetExits( ([ "southwest" : V_ROOM + "library",
	       "south" : V_ROOM + "fl12c" ]) );
}