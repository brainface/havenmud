#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("guest room");
  SetLong("Whoever owns this tower thinks highly of guests.  This "
	"room is very lavishly decorated and comfortable.  The "
	"walls are painted in a very easy shade of white and the "
	"lights are bright enough to read by.  There are three beds "
	"here.  The lack of windows is the only shortcoming to "
	"this room.  To the east is the staircase.");
  SetItems( ([ "room" : "This room is very lavish.",
	({"light","lights"}) : "The lights in this room seem to eminate from "
		"everywhere.  They are very soft.",
	({"window","windows"}) : "There are not any windows in this room.",
	({"wall","walls"}) : "The walls are painted in a soft eggshell white. "
		"They are undecorated.",
	({"bed","beds"}) : "The beds are covered in many blankets.  They are filled "
		"with feathers and very soft.  They are also covered "
		"in pillows.",
	"ceiling" : "The ceiling is painted in a soft white.",
	({"stairs","staircase"}) : "The stairs are back to the east.",
	"tower" : "This is the third floor of the tower.",
	]) );
  SetItemAdjectives( ([ "room" : ({"guest","lavish","comfortable"}),
	"wall" : ({"painted","","white"}),
	]) );
  SetInventory( ([
	V_NPC + "guest" : 1,
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "This room is very quiet." ]) );  
  SetSmell( ( [ "default" : "The room still smells new." ]) );
  SetExits( ([ "east" : V_ROOM + "fl03e" ]) );
}