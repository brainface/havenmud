#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the catwalk along the east wall");
  SetLong("The wind is softly blowing along catwalk.  Standing out here on "
	"the catwalk, there is a great view of Kailie.  There are glass "
	"walls behind and the small catwalk keeping anyone from falling to "
	"their death.  The nearest city is viewable from here.  The lights "
	"highlight the sky.  The catwalk leads around the tower to the "
	"southwest and northwest.  The exit to the stairwell is to the west.");
  SetItems( ([  "catwalk" : "The catwalk is very narrow.  It is about ten "
	"floors above the ground and is made of stone jutting out from the "
	"tower.",
	"Kailie" : "The mountains of Kailie are very pretty when viewed "
		"from this height.",
	({"wall","walls"}) : "The walls are glass and make the "
		"tower seem even higher than it is.",
	"stone" : "The stone that makes up the catwalk is cut very smooth "
		"and juts out from the stone work of the floor below.  It "
		"is the same stone used in the walls and floor.",
	({"city","light","lights"}) : "The city lights are almost the only "
		"thing noticeable from this height.",
	"down" : "Looking down does not seem like the smartest thing to do.",
	]) );
  SetItemAdjectives( ([ "catwalk" : ({"disturbing"}),
	"wall" : ({"glass"}),
	"stone" : ({"gray","cold"}),
	]) );
  SetInventory( ([
	V_NPC + "bird" : 1,
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The wind howls by along the catwalk." ]) );  
  SetSmell( ( [ "default" : "The air smells like fresh outdoor air." ]) );
  SetExits( ([ "northwest" : V_ROOM + "fl09n",
	       "west" : V_ROOM + "fl09c",
	       "southwest" : V_ROOM + "fl09s" ]) );
}