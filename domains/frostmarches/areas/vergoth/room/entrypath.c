#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a trail in the mountains");
  SetLong("The forest looms in over the trail forming a canopy "
	"swallowing the path and hiding the sky overhead.  From here "
	"the tower is coming into view along the horizon that has "
	"seemingly come from nowhere.  An entry can be seen to the "
	"west from here.  To the east the trail returns back to "
	"the main road.");
  SetDomain("FrostMarches");
  SetClimate("arctic");
  SetItems( ([  
	"entry" : "To the west there is an entry to the tower.",
	"trail" : "The trail is nothing more than a dirt path meandering "
		"through the mountains.  It runs in a east/west direction",
	"tower" : "The tower appears to be carved from a black stone that "
		"had to have come from miles away.  There are strange "
		"markings all along the outside of the walls that stretch "
		"as far the the eye can see going up.  At the upper levels "
		"of the tower, there are three spires, one center spire and "
		"two smaller spires that branch off to the east and west "
		"sides of the tower.  The very upper levels to the tower "
		"seem to glow against the horizon as though the sun is "
		"lying behind the center spire.",
	"horizon" : "The horizon is hidden by the surrounding trees.",
	({"canopy","forest","trees","treeline"}) : "The forest is thick "
		"with trees of every size.  They form a canopy overhead "
		"that blocks out most of the light this deep into the "
		"mountains.",
	"sun" : "The sun would be welcome in this cold enviroment, but it "
		"is hidden by the forest canopy overhead.",
	]) );
  SetItemAdjectives( ([
	"trail" : ({ "dirt" }),
	"tower" : ({ "black","carved","stone" }),
	"horizon" : ({ "hidden" }),
	]) );  
  SetSmell( ([ "default" : "The forest smells of trees and other growing "
		"things." ]) );
  SetListen( ([ "default" : "The sounds of civilization can be heard to "
		"the east." ]) );  
  SetExits( ([ "west" : V_ROOM + "fl01e",
      "east" : "/domains/frostmarches/virtual/durgorothroad/-10,10",
	]) );
}
