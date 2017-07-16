#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("seventh floor stairs");
  SetLong("This is the second level to the short spiral staircase.  The "
	"walls are glowing slightly from the inherent magic that seems to "
	"keep this tower standing.  The stairs are cut from a dull gray "
	"stone set into a wrought iron frame.  The stairs are very short "
	"though and appear to continue going up at least one more level.  "
	"Down leads back to the hallway.");
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
  SetListen( ([ "default" : "The staircase is silent." ]) );  
  SetSmell( ( [ "default" : "The air smells of magic." ]) );
  SetExits( ([ "up" : V_ROOM + "fl08c",
	       "down" : V_ROOM + "fl06c" ]) );
}