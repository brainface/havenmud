#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("east spire stairs to overlook");
  SetLong("A set of stairs starts here.  The stairs are cut from a "
	"gray stone and set into a wrought iron frame.  The frame is "
	"warm to the touch and some of the steps appear to have "
	"been broken by a great force.  The walls have been scorched "
	"by a great heat.  There appears to have been a battle here.  "
	"To the east is the hallway leading back to the central "
	"staircase and there is a set of stairs here going up.");
  SetItems( ([  ({"stairs","staircase"}) : "The stairs are carved from "
	"a gray stone and set into a wrought iron frame.  They seem to "
	"be very sturdy.",
	({"floor","wall","walls"}) : "The floor and walls are cut from "
		"a cold and gray stone that was probaly cut in some mine "
		"by slaves miles away.  They have been scorched black "
		"by some great amount of heat.",
	"stone" : "The stone everything is made of has been cut very "
		"smooth and appears to be fitted in a nice tight pattern "
		"in the stairs, walls, and floor.  All the stone work "
		"here has been blackened by a great heat.",
	"frame" : "This frame is made from a heavy wrought iron to "
		"support the massive weight of all the stairs.  It is "
		"warm to the touch as if it had come out of a fire not "
		"long ago.  The upper portions of the frame have droplets"
		"that only form when metal is put under extreme heat.",
	"droplets" : "The droplets on the frame have been formed from "
		"the heat that this frame has been subjected to.",
	]) );
  SetItemAdjectives( ([ "walls" : ({"blackened","stone","blackened"}),
	"hallway" : ({"dull","lifeless"}),
	"stone" : ({"gray","blackened","black","cold"}),
	"frame" : ({"wrought","iron","warm"}),
	"stairs" : ({"spiral"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The wind whistles through the staircase." ]) );  
  SetSmell( ( [ "default" : "The east tower smells like burning wood." ]) );
  SetExits( ([ "west" : V_ROOM + "et1",
	       "up" : V_ROOM + "et3" ]) );
}