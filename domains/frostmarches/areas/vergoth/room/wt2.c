#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("west spire stairs to dining room");
  SetLong("A set of stairs starts here.  The stairs are cut from a "
	"gray stone and set into a wrought iron frame.  The walls and "
	"floor are cut from the the same gray rock as the spiral "
	"staircase.  Nothing has been done to decorate this hallway.  "
	"To the east is the hallway leading back to the central "
	"staircase and there is a set of stairs here going up.");
  SetItems( ([  ({"stairs","staircase"}) : "The stairs are carved from "
	"a gray stone and set into a wrought iron frame.  They seem to "
	"be very sturdy.",
	({"floor","wall","walls"}) : "The floor and walls are cut from "
		"a cold and gray stone that was probaly cut in some mine "
		"by slaves miles away.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.",
	"frame" : "This frame is made from a heavy wrought iron to "
		"support the massive weight of all the stairs.  It "
		"spirals up to the next floor.",
	]) );
  SetItemAdjectives( ([ "wall" : ({"gray","stone"}),
	"hallway" : ({"dull","lifeless"}),
	"stone" : ({"gray","cold"}),
	"frame" : ({"wrought","iron"}),
	"stairs" : ({"spiral"}),
	]) );
  SetInventory( ([
	V_NPC + "rat" : 2,
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The west tower is very quiet." ]) );  
  SetSmell( ( [ "default" : "The air here smells fresh." ]) );
  SetExits( ([ "east" : V_ROOM + "wt1",
	       "up" : V_ROOM + "wt3" ]) );
}