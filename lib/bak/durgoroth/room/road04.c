// Title: Durgoroth Town
// File: road04.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1997
// Abstract: West end of the east-west road inside the town of Durgoroth
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("near the west wall of Durgoroth");
	SetDayLong("Thus road continues off to the east, towards the "
		"center of town. Directly to the west is the western wall "
		"of the fortress, with a small stair leading up from the "
		"street to the top of the wall. To the south is the "
		"infamous Raunchy Goblin tavern. To the north is the large "
		"structure of the Durgoroth arena. Its massive circular "
		"structure dwarfing the tavern across the way.");
	SetNightLong("This road continues off into the darkness to "
		"the east. To the west looms the black form of the fortress "
		"western wall. A small stair leads up from the street to the "
		"top of the wall. To the south is the infamous Raunchy "
		"Goblin tavern, its windows shining out like beacons in the night. "
		"To the north stands the now quiet arena. Its massive "
		"circular structure blocking out an entire quadrant of stars. ");
	SetObviousExits("east, up");
	SetClimate("sub-arctic");
	SetDomain("FrostMarches");
	SetItems( ([
		({"western wall","massive wall","massive walls","walls","wall"}) :
			"The massive walls of ancient, "
			"weather worn black stone surround the town.",
		({"small stair", "stair", "staircase" }) : "A small, worn, stair "
			"of cut stone blocks leads up from the edge of the road to "
			"the top of the wall.",
		({"cobblestone road","road"}) :
			"The cobblestone road ends at the edge of the wall, and "
			"continues the other direction, off to the east, towards "
			"the center of the town. ",
		({"fortress","durgoroth"}) : "The massive fortress of "
			"Durgoroth surrounds the town within.",
		]) );
		if(query_night()) {
		AddItem(({"raunchy goblin tavern", "raunchy goblin", "tavern"}),
			"The large wooden structure leans up against the wall. "
			"The windows shine out like a beacon in the cold night. "
			"The raucous sounds of drunken merry making drift out "
			"into the quiet night street. ");
		AddItem(({"durgoroth arena", "arena"}), "The massive circular "
			"structure blocks out an entire quadrent of the stars, "
			"dwarfing the structures next door and across the street. ");
			}
		else {
		AddItem(({"raunchy goblin tavern", "raunchy goblin", "tavern"}),
			"The large wooden structure leans up against the wall. "
			"The tavern's windows are dark now, the majority of its "
			"business being done in the night time.");
		AddItem(({"durgoroth arena", "arena"}), "It's massive circular "
			"structure dwarfing the tavern across the way. The loud "
			"sounds of boo's and cheers come from within, with an "
			"occasional loud clang of a sword striking a shield with "
			"great force.");
		}
	SetExits( ([
		"east" : D_ROOM+"/road05",
		"up" : D_ROOM+"/wall02",
		]) );
	SetEnters( ([
		"arena" : D_ROOM+"/arena",
           "tavern" : D_ROOM+"/tavern",
		]) );
	if(query_night())
		SetListen( ([
			"default" : "The sound of raucous drunken merry making drifts "
				"out into the quiet night street.",
		]) );
	else
		SetListen( ([
			"default" : "The loud sounds of \"Boo's\" and cheers come from "
				"the arena, with an occasional loud clang of a weapon "
				"striking a shield.",
		]) );
	}
