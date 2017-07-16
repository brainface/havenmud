#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the catwalk along the west wall");
  SetLong("The wind is softly blowing along the catwalk.  Standing out here "
	"on the catwalk, there is a great view of Kailie.  There are glass "
	"walls behind and the small catwalk keeping anyone from falling to "
	"their death.  The forest surrounding the tower can be seen stretching "
	"out for miles in every direction.  The trees barely seem to rise high "
	"enough to touch the tower at about the fifth floor.  The catwalk "
	"continues around the tower to the northeast and southeast.");
  SetItems( ([  "catwalk" : "The catwalk is very narrow.",
	"Kailie" : "Kailie is very pretty when viewed from "
	"this height.",
	({"wall","walls"}) : "The walls are glass and make the "
	"tower seem even higher than it is.",
	({"tree","trees","forest"}) : "The forest is very regal "
	"and untouched.  The trees all stand proud and defiant of "
	"mans conquest over it.",
	]) );
  SetItemAdjectives( ([ "catwalk" : ({"disturbing"}),
	"stone" : ({"gray","cold"}),
	"forest" : ({"beautiful","dense"}),
	"wall" : ({"glass"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The wind howls by." ]) );  
  SetSmell( ( [ "default" : "The air smells like fresh outdoor air." ]) );
  SetExits( ([ "southeast" : V_ROOM + "fl09s",
	       "northeast" : V_ROOM + "fl09n" ]) );
}