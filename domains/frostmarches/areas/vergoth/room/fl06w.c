#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("sixth floor landing along the west wall");
  SetLong("The stairs stop here on a landing.  The walls and floor are very "
	"dull and carved from stone.  There is a painting on the wall here. "
	" The stairs lead down to the northeast.  A hallway leads to the "
	"east.");
  SetItems( ([ ({"wall", "walls","floor"}) : "The walls and floor are "
		"cut from a gray and very dull to look at stone.",
	({"staircase","stairs"}) : "The stairs are cut from a very "
		"dull and gray stone.  They are layered one on top of the "
		"other up to this landing.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	"painting" : "This by far is the worst painting of them all.  It is "
		"a picture a gaping dragon's maw filled with razor sharp "
		"teeth.  The mouth of the beast is filled with the limbs "
		"and blood of its latest victim.",
	"landing" : "The landing is carved from stone and serves as a "
		"stopping point before leading to another staircase.",
	]) );
  SetItemAdjectives( ([ "wall" : ({"dull","stone","gray"}),
	"stairs" : ({"dull","stone","layered"}),
	"stone" : ({"gray","cut","smooth"}),
	"painting" : ({"disturbing"}),
	]) );
  SetInventory( ([
	V_NPC + "rat" : 5,
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The wind sings as it whistles through the "
	"staircase." ]) );  
  SetSmell( ( [ "default" : "The air smells of magic, as though it is the "
	"reason there is air here." ]) );
  SetExits( ([ "northeast" : V_ROOM + "fl06n",
	       "east" : V_ROOM + "fl06c" ]) );
}
