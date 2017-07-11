#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("kitchen");
  SetLong("This kitchen is very well equiped.  There are pots and "
	"pans everywhere.  There are two fireplaces here, both lit "
	"with blazing fires.  No one is here and it seems as though "
	"no one has cooked here for years.  The stairs are back to "
	"the east.");
  SetItems( ([ "room" : "This room is very lavish.",
	({"light","lights"}) : "The lights in this room seem to eminate from "
		"everywhere.  They are very soft.",
	({"window","windows"}) : "There are not any windows in this room.",
	({"wall","walls"}) : "The walls are painted in a soft eggshell white."
		"  They are undecorated.",
	({"bed","beds"}) : "The beds are covered in many blankets.  They are "
		"filled with feathers and very soft.  They are also covered "
		"in pillows.",
	"ceiling" : "The ceiling is painted in a soft white.",
	({"stairs","stairwell"}) : "The stairs are back to the east.",
	]) );
  SetItemAdjectives( ([ "room" : ({"guest","lavish","comfortable"}),
	"wall" : ({"painted","","white"}),
	]) );
  SetInventory( ([
	V_NPC + "skeleton_cook" : 3,
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The tower is very quiet." ]) );  
  SetSmell( ( [ "default" : "The tower smells moldy." ]) );
  SetExits( ([ "east" : V_ROOM + "fl04e" ]) );
}