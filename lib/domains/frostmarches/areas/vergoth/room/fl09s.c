#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the catwalk along the south wall");
  SetLong("The wind is softly blowing along the catwalk.  Standing out here "
	"on the catwalk, there is a great view of Kailie.  There are glass "
	"walls behind and the small catwalk keeping anyone from falling to "
	"their death.  The forest surrounding the tower can be seen stretching "
	"out for miles in every direction.  The trees barely seem to rise high "
	"enough to touch the tower at about the fifth floor.  The catwalk "
	"continues around the tower to the northwest and northeast.");
  SetItems( ([  "catwalk" : "The catwalk is very narrow.  It is about ten "
		"floors above the ground and is made of stone jutting out from the "
		"tower.",
	"Kailie" : "The mountains of Kailie stand very tall and majestic over "
		"the tower.",
	({"wall","walls"}) : "The walls are glass and make the "
		"tower seem even higher than it is.",
	"stone" : "The stone that makes up the catwalk is cut very smooth and "
		"juts out from the stone work of the floor below.  It is the "
		"same stone used in the walls and floor.",
	"down" : "Looking down does not seem like the smartest thing to do.",
	({ "mountain","mountains" }) : "The mountains surround the whole area."
		"  They stand tall and majestic above the tower.",
	]) );
  SetItemAdjectives( ([ "catwalk" : ({"disturbing"}),
	"wall" : ({"glass"}),
	"stone" : ({"gray","cold"}),
	"mountain" : ({"tall","majestic"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The wind howls by along the catwalk." ]) );  
  SetSmell( ( [ "default" : "The air smells like fresh outdoor air." ]) );
  SetExits( ([ "northeast" : V_ROOM + "fl09e",
	       "northwest" : V_ROOM + "fl09w" ]) );
}