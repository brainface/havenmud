// Title: Durgoroth Town
// File: wall04.c
// Author: Tim Morris aka Morgoth@Haven
// Date: January 1998
// Abstract: Southwestern tower of the Durgoroth town
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("southwestern guard tower");
	SetLong("This tower lies "
		"at the intersection of the western and southern walls "
		"of the fortress. Two wooden doors lead out of the "
		"tower, one to the north and one to the east. At the "
		"back of the tower is a small staircase leading up through "
		"the ceiling of the room to the roof of the tower. "
		"This is where the guards relax on their off time. In "
		"the middle of the tower is a small wooden table, and "
		"several cots. There are usually several off-duty guards "
		"in this room, sleeping or playing cards.");
	SetClimate("indoors");
	SetDomain("FrostMarches");
	SetAmbientLight(35);
	SetObviousExits("north, east, up");
	SetItems( ([
		({"southwestern guard tower", "guard tower", "tower"}) : 
			"This large tower is one of the two at each of the "
			"intersecting corners of the walls of the fortress."
			"It's interior houses the sleeping and eating area "
			"of a portion of the fortress' guard. As well "
			"as racks of weapons and various tools related to "
			"the warfare trade.",
		({"doors", "door", "wooden doors", "wooden door"}) :
			"Two small, thick, hardwood doors lead out of the "
			"tower. One to the north, and one to the east. ",
		({"staircase", "stair", "small staircase", "small stair",
			"trap-door", "trapdoor", "trap door"}) :
			"A small set of spiral stairs leads up to to a small, "
			"heavy wooden trap-door to the parapit of the tower. ",
		({"ceiling"}) : "The ceiling is made of heavy wooden planks "
			"laid across a series of supporting beams.",
		({"small wooden table", "wooden table", "small table",
		"table"}) : "A small table of stained wood sits in "
			"the center of the room. Obviously intended for use "
			"by the off duty guards.",
		({"cot", "cots", "canvas cots", "blankets", "blanket",
		"canvas cot"}) : "A half dozen dirty canvas cots line "
			"the walls. Spread on them are an array of patched and "
			"worn blankets.",
		]) );
	SetExits( ([
		"north" : D_ROOM+"/wall03",
		"east" : D_ROOM+"/wall05",
		"up" : D_ROOM+"/tower01",
		]) );
	SetInventory( ([
		D_NPC + "/off_guard" : (random(3)+1),
		]) );
	}
