#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("west tower hallway");
  SetLong("The hallway is very short and appears to have been used recently.  "
	"The walls are panelled in some exotic wood and the floor is "
	"carpeted with what appears to be animal hides.  There are no "
	"windows here and the walls are bare.  Whoever owns the tower "
	"has not done much to decorate it would seem.  To the west lies "
	"the staircase for the western spire and to the east lies "
	"the central staircase.");
  SetItems( ([  "hallway" : "The hallway is very short and undecorated.",
	({"stairs","stairwell"}) : "There are stairs to the east "
	"and to the west",
	({"wall","walls","panel"}) : "The walls are paneled in a very "
		"exotic wood.  They are undecorated and dull.",
	({"floor","floors"}) : "The floors are carpeted in some "
		"animal hides.",
	({"hide","hides"}) : "The animal hides covering the floors "
		"appear to be made from the skin of a bear.",
	({"window","windows"}) : "There are not any windows here.",
	"tower" : "The tower is tall and very dull",
	"wood" : "The wood covering the walls is a very dark wood, "
		"almost to the point of being a blue.  It is definetly "
		"not a wood from this land.",
	]) );
  SetItemAdjectives( ([ "hallway" : ({"short"}),
	"wall" : ({"paneled","dull","undecorated"}),
	"floor" : ({"carpeted"}),
	"hide" : ({"animal"}),
	"wood" : ({"exotic"}),
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The hallway is very quiet." ]) );  
  SetSmell( ( [ "default" : "The hallway smells of dust and mold." ]) );
  SetExits( ([ "east" : V_ROOM + "fl04w",
	       "west" : V_ROOM + "wt2" ]) );
}