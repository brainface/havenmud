#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("ninth floor landing");
  SetLong("This part of the tower has walls that are all glass.  They "
	"seemlessly fit into the rock walls from below.  Outside the "
	"glass walls, there is a catwalk around the tower.  The "
	"stairs continue lead up to the tenth floor up and and down to the "
	"eighth floor.  To the east is an exit to the catwalk.");
  SetItems( ([ ({"wall","walls"}) : "The walls are made of an unbreakable "
	"glass.  There is a catwalk viewable from here.",
	({"rock","rocks"}) : "The rocks from the walls below are "
		"seeable through the glass walls on this floor.",
	"catwalk" : "There is a small catwalk that wraps all the "
		"way around the tower.  There is a good view of Kailie "
		"from there.",
	"stone" : "The stone that the steps are made of has "
		"been cut very smooth and appears to be fitted very tight "
		"into the iron frame.  It is the same stone used in the "
		"walls and floor.",
	"frame" : "This frame is made from a heavy wrought iron to "
		"support the massive weight of all the stairs.  It "
		"spirals up to the next floor.",
	({"stairs","staircase"}) : "The stairs are carved from "
		"a gray stone and set into a wrought iron frame that seems to "
		"be very sturdy.  The staircase appears to be very short and easy "
		"to navigate.It is made from stones cut and set into a wrought iron "
		"frame.",	]) );
  SetItemAdjectives( ([ "stairs" : ({"spiral","stone"}),
	"stone" : ({"gray","cold"}),
	"frame" : ({"wrought","iron"}),
	"wall" : "glass",
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The wind whistles outside on the catwalk." ]) );  
  SetSmell( ( [ "default" : "The air here smells very fresh." ]) );
  SetExits( ([ "up" : V_ROOM + "fl10c",
	       "east" : V_ROOM + "fl09e",
	       "down" : V_ROOM + "fl08c" ]) );
}