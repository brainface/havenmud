#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("east tower hallway");
  SetLong("The hallway is very short and appears to have been used recently.  "
	"The walls are paneled in some exotic wood and the floor is "
	"carpeted with what appears to be animal hides.  There are not "
	"any windows here and the walls are bare.  Whoever owns the tower "
	"has not done much to decorate here.  To the east lies the "
	"staircase for the eastern spire and to the west is the central "
	"staircase.");
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
	"wood" : "The wood covering the walls is a very dark wood, almost "
		"to the point of being a blue.  It is definitely not a wood "
		"from this land.",
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
  SetListen( ([ "default" : "The wind whistles through the hallway." ]) );  
  SetSmell( ( [ "default" : "The hallway smells of fresh air." ]) );
  SetExits( ([ "east" : V_ROOM + "et2",
	       "west" : V_ROOM + "fl05e" ]) );
}