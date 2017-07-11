#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("east spire stairs to overlook");
  SetLong("This is the second level to the short spiral staircase.  "
	"Some of the steps are busted all the way through and it has "
	"become difficult to navigate up the staircase.  The iron "
	"frame of the staircase has become extremely hot to the touch.  "
	"The stairs are very short though and appear to enter into a "
	"room at the next level.  Going down will return back to the "
	"hallway and up leads into a room.");
  SetItems( ([  ({"stairs","staircase"}) : "The spiral staircase is "
		"very short and easy to navigate compared to the central "
		"staircase.  It is made from stones cut and set into a "
		"wrought iron frame.",
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
		"very hot to the touch as if it had come out of a fire "
		"a few minutes ago.  Portions of the frame have droplets"
		"that only form when metal is put under extreme heat.",
	"droplets" : "The droplets on the frame have been formed from "
		"the heat that this frame has been subjected to.",
	]) );
  SetItemAdjectives( ([ "walls" : ({"blackened","stone","blackened"}),
	"hallway" : ({"dull","lifeless"}),
	"stairs" : ({"spiral"}),
	"stone" : ({"gray","blackened","black","cold"}),
	"frame" : ({"wrought","iron","warm"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The winds blows overhead closeby." ]) );  
  SetSmell( ( [ "default" : "The stairs smell of smoke." ]) );
  SetExits( ([ "down" : V_ROOM + "et2",
	       "up" : V_ROOM + "overlook" ]) );
}