#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("tower den");
  SetLong("This is the den for the tower.  There are not any windows in "
	  "this room and the walls are panelled in a dark wood.  The "
	  "ceiling is vaulted and there is a large chandelier hanging "
	  "down.  There are two couches and a large table in the middle "
	  "of the room.  To the east is the exit back to the stairwell. ");
  SetItems( ([ "den" : "The den is very elegant.",
	       ({"window","windows"}) : "There are not any windows in this room.",
	       ({"wall","walls"}) : "The walls are paneled in a dark wood.",
	       "wood" : "The walls are paneled in some dark wood that has "
			"glossed over and shows no signs of aging.  It is "
			"probaly from some sort of foreign tree.",
	       "ceiling" : "The ceiling is vaulted and paneled at the very top.",
	       "chandelier" : "The chandelier is made of crystals and appears to "
			      "lit by some magical light.",
	       ({"couch","couches"}) : "The couches are made of a very soft velvet and "
				       "will seat three.",
	       "table" : "The table is cut of stone and is very dull.",
	       ({"stairs","stairwell"}) : "The stairs are back to the east.",
	       "tower" : "This is the den in first floor of the tower.",
	]) );
  SetItemAdjectives( ([ "den" : ({"elegant"}),
			"wall" : ({"paneled","panel","dark","wood","glossed"}),
			"wood" : ({"dark","glossed","foreign"}),
			"ceiling" : ({"vaulted","paneled",}),
			"chandelier" : ({"crystal","large"}),
			"couch" : ({"velvet","soft"}),
			"table" : ({"stone","dull","large"}),
		]) );
  SetInventory( ([
	V_NPC + "golem" : 1,
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The den is very quiet." ]) );  
  SetSmell( ( [ "default" : "The den smells of dust and decay." ]) );
  SetExits( ([ "east" : V_ROOM + "fl02e" ]) );
}
