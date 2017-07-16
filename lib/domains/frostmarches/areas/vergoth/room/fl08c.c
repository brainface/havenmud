#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("eighth floor stairs");
  SetLong("This is the third level to the short spiral staircase.  The walls "
	"are glowing slightly from the inherent magic that seems to keep "
	"this tower standing.  The stairs are cut from a dull gray stone set "
	"into a wrought iron frame.  They are very short though and appear "
	"to enter into a room at the next level.  Down will returns back to "
	"the hallway and up seems to lead into a landing in the stairs.");
  SetItems( ([  ({"stairs","staircase"}) : "The sprial staircase is "
		"very short and easy to navigate compared to the central "
		"staircase.  It is made from stones cut and set into a "
		"wrought iron frame.",
	({"walls","wall"}) : "The walls are cut from a dull "
		"gray stone which glows with the essence of magic.",
	({"landing"}) : "The landing is not viewable from here.",
	({"hallway"}) : "The hallway is back down the staircase.",
	]) );
  SetItemAdjectives( ([  "stairs" : ({"spiral","stone"}),
	"wall" : ({"gray","stone"}),
	"stone" : ({"gray","cold"}),
	"frame" : ({"wrought","iron"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The tower is very quiet." ]) );  
  SetSmell( ( [ "default" : "The tower smells of moldy dust." ]) );
  SetExits( ([ "up" : V_ROOM + "fl09c",
	       "down" : V_ROOM + "fl07c" ]) );
}