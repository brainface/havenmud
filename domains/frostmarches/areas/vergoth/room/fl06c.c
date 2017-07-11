#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("sixth floor hallway");
  SetLong("The top of the tower is near.  The staircase has shrunk down "
	"to stone slabs set in a wrought iron frame work.  They seem to "
	"stretch up higher than possible, definitely not by nature's hand, "
	"but the hands of magic.  The stone walls here glow with the "
	"essence of magic that is imbued into them.  To the west lies "
	"the central staircase leading down, while going up leads to the "
	"top of the tower.");
  SetItems( ([  ({"stairs","staircase"}) : "The stairs are carved from "
		"a gray stone and set into a wrought iron frame that seems to "
		"be very sturdy.  The staircase appears to be very short and easy "
		"to navigate.It is made from stones cut and set into a wrought iron "
		"frame.",
	({"wall", "walls","floor"}) : "The walls and floor are cut from a "
		"gray and very dull to look at stone.  They glow slightly "
		"as if from magic.",
	"stone" : "The stone that the steps are made of has "
		"been cut very smooth and appears to be fitted very tight "
		"into the iron frame.  It is the same stone used in the "
		"walls and floor.",
	"frame" : "This frame is made from a heavy wrought iron to "
		"support the massive weight of all the stairs.  It "
		"spirals up to the next floor.",
	]) );
  SetItemAdjectives( ([  "stairs" : ({"spiral","stone"}),
	"wall" : ({"gray","stone"}),
	"stone" : ({"gray","cold"}),
	"frame" : ({"wrought","iron"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The hallway has grown quiet here." ]) );  
  SetSmell( ( [ "default" : "The air smells of magic." ]) );
  SetExits( ([ "west" : V_ROOM + "fl06w",
	       "up" : V_ROOM + "fl07c" ]) );
}