#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("eleventh floor stairs");
  SetLong("This is the fifth level to the short spiral staircase.  "
	"The walls are glowing brightly and the air is tingling with "
	"the inherant magic that seems to keep this tower standing.  The "
	"stairs are cut from a dull gray stone set into a wrought "
	"iron frame.  The stairs are very short though and lead to "
	"a landing on the next level.  Down leads to the catwalk.");
  SetItems( ([  ({"stairs","staircase"}) : "The sprial staircase is "
		"very short and easy to navigate compared to the central "
		"staircase.  It is made from stones cut and set into a "
		"wrought iron frame.",
	({"walls","wall"}) : "The walls are cut from a dull "
		"gray stone which glows with the essence of magic.",
	({"landing"}) : "The landing is not viewable from here.",
	({"catwalk"}) : "The catwalk is back down the staircase.",
	]) );
  SetItemAdjectives( ([  "stairs" : ({"spiral","stone"}),
	"wall" : ({"gray","stone"}),
	"stone" : ({"gray","cold"}),
	"frame" : ({"wrought","iron"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The staircase hums with the energies in "
		"the walls." ]) );  
  SetSmell( ( [ "default" : "The air smells heavily of magic." ]) );
  SetExits( ([ "up" : V_ROOM + "fl12e",
	       "down" : V_ROOM + "fl10c" ]) );
}