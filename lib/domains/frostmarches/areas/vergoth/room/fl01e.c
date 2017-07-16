#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("entry to the tower");
  SetLong("This is the entry way into the mysterious tower noticed from "
	"outside.  The tower is not very large around, but it makes up "
	"for that in sheer height.  The walls and floor are a carved "
	"stone that doesn't appear to be from this land.  There is a "
	"room off to the west, and a long winding staircase to the "
	"northwest.  To the east is the exit from the tower.");
  SetItems( ([ "tower" : "This is the first floor of the tower.  It is "
		"not very large around, but it appears to rise up about "
		"twleve floors.",
	"room" : "There is a room to the west",
	"exit" : "The exit to the tower is east from here.",
	({ "wall", "walls", "stone","floor" }) : "The walls and the floor "
		"are carved from a gray stone that is not of this land.  "
		"They are cut and assembled to perfection, almost better "
		"than a dwarfs own work.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	({ "stairs", "staircase" }) : "The stairs are very narrow and lead "
		"to the top of the tower.  They are cut from gray stone and "
		"and spiral to the top of the tower." ]) );
  SetItemAdjectives( ([ "tower" : ({"mysterious"}),
	"stone" : ({"carved","gray","cut","carved"}),
	"walls" : ({"stone","gray","carved"}),
	"floor" : ({"stone","gray","carved"}),
	"stairs" : ({"spiral","long","narrow"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The tower is very quiet." ]) );  
  SetSmell( ( [ "default" : "This part of the tower smells ancient but "
	"rarely used." ]) );
  SetExits( ([ "northwest" : V_ROOM + "fl01n",
               "west" : V_ROOM + "entry",
	       "east" : V_ROOM + "entrypath",
		]) );
}