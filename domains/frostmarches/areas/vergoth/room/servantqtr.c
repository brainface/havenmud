#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("servant quarters");
  SetLong("Whoever owns this tower doesn't think as highly of his "
	  "servants as he does of his guests.  This room is very plain "
	  "and contains just the bare essentials to live by.  The "
	  "walls are bare and cut from the same stone as the staircase is.  "
	  "The room is dark and not lit.  There are 5 beds "
	  "here.  The lack of windows only adds to the overall "
	  "dreariness.  To the east is the staircase.");
  SetItems( ([ "room" : "This room is very plain.",
	       ({"window","windows"}) : "There are not any windows in this room.",
	       ({"wall","walls"}) : "The walls are stone and not decorated"
				"with anything.",
	       ({"bed","beds"}) : "The beds are covered with a single "
				"blanket and one old pillow.",
	       ({"stairs","stairwell"}) : "The stairs are back to the east.",
	]) );
  SetItemAdjectives( ([ "room" : ({"servant"}),
			"wall" : ({"painted","","white"}),
		]) );
  SetInventory( ([
	V_NPC + "zombie_servant" : 5,
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(5);
  SetListen( ([ "default" : "This room is very quiet." ]) );  
  SetSmell( ( [ "default" : "This room smells used." ]) );
  SetExits( ([ "east" : V_ROOM + "fl05e" ]) );
}