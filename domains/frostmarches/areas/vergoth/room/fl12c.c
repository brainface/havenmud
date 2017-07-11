#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("twelfth floor waiting room");
  SetLong("This guest waiting room is very nicely done.  There is a painting "
	"on the wall and burning candlebras in every corner.  The room is "
	"nicely lit with a bright glow from the surrounding walls.  "
	"There are 4 chairs and a small table for drinks.  There is a lab "
	"off to the north, a library to the west, and a bedroom to the "
	"south.  East leads to the central staircase.");
  SetItems( ([  "room" : "This room is nicely decorated.",
	"painting" : "This painting actually seems normal.  It is "
	"a painting of this tower.  There are three spires on this "
		"tower.",
	({"candlebra","candlebras"}) : "The candlesbras each hold "
		"three candles and are made of brass.  Upon further inspection, "
		"none of the candles are real.  The candlebras are lit by a "
		"magical fire, although with the emanations from the rocks, "
		"they are not needed.",
	({"wall", "walls","floor"}) : "The walls and floor are cut from a "
		"gray and very dull to look at stone.  It is a gray color "
		"and is glowing brightly.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	({"chair","chairs"}) : "The chairs are cut from a white wood "
		"and covered in a velvet seat cushion.",
	"table" : "The table is small, made just for holding drinks "
		"during conversation.  It is made of a white colored wood.",
	({"stairs","staircase"}) : "The stairs are back to the east.",
	"wood" : "The wood that the table and chairs are carved from is a "
		"very light colored wood, almost to the point of being white.  "
		"The grain is not very tight, but the furniture looks strong "
		"enough to support a persons weight.",
	]) );
  SetItemAdjectives( ([ "room" : ({"guest","waiting","decorated"}),
	"candelbra" : ({"burning"}),
	"wall" : ({"dull","stone","gray"}),
	"stairs" : ({"endless","dull","stone","layered"}),
	"stone" : ({"gray","cut","smooth"}),
	"painting" : ({"wall"}),
	"wood" : ({"white"}),
	"brew" : ({"alcoholic"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetListen( ([ "default" : "This room tingles with sound from the magic "
		"emanating from the walls." ]) );  
  SetSmell( ( [ "default" : "This room smells like the air after lightening "
		"hits the ground nearby.",
	"brew" : "The brew smells of strong alcohol.",
	]) );
  SetInventory( ([
	V_NPC + "undead_mage" : 1,
	V_OBJ + "brandy" : 1,
   ]) );
  SetExits( ([ "north" : V_ROOM + "lab",
	       "west" : V_ROOM + "library",
	       "south" : V_ROOM + "fl12s",
	       "east" : V_ROOM + "fl12e" ]) );
}