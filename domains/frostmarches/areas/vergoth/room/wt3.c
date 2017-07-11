#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("west spire stairs to dining room");
  SetLong("This is the second level to the short spiral staircase.  "
	"The walls are undecorated and the stairs are cut from a "
	"dull gray stone set into a wrought iron frame.  The stairs "
	"are very short though and appear to enter into a room at "
	"the next level.  Going down leads to a hallway and up leads "
	"to a room.");
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
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The staircase is very quiet." ]) );  
  SetSmell( ( [ "default" : "The staircase smells faintly of spices." ]) );
  SetExits( ([ "down" : V_ROOM + "wt2",
	       "up" : V_ROOM + "dining" ]) );
}