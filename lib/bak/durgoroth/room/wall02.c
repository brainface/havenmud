// Title: Durgoroth Town
// File: wall02.c
// Author: Tim Morris aka Morgoth@Haven
// Date: January 1998
// Abstract: Western wall of the Durgoroth town
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("west wall of Durgoroth");
	SetDayLong("This wall continues to the north and south. To the "
		"north the wall ends against the mountain side, while to the "
		"south it joins with the southwestern guard tower of the "
		"fortress. To the west the mountain falls away, down into the "
		"valley far below, while to the north the mountain rises up "
		"to incomprehendable heights. To the east a small stair leads "
		"down from the wall to the street below. To the northeast the "
		"huge Durgoroth arena can be seen, its massive circular "
		"structure dwarfing that of the Raunchy Goblin tavern across "
		"the street to the southeast.");
	SetNightLong("This wall continues into the darkness to the north "
		"and south. A small stair leads down from the wall to the "
		"street below. On the other side of the wall lies a sea of "
		"blackness where the mountain drops away, down to the valley, "
		"while to the north the mountain rises away into the dark night "
		"sky. To the northeast lies the now quiet black form of the "
		"Durgoroth arena, its huge circular structure dwarfing that "
		"of the Raunchy Goblin tavern across the street to the "
		"southeast.");
	SetObviousExits("north, south, down");
	SetClimate("sub-arctic");
	SetDomain("FrostMarches");
	SetItems( ([
		({ "wall", "walls","towers", "fortress" }) : "The massive "
			"walls of ancient, weather worn black stone surround the "
			"town. At each corner of the main wall is a large guard "
			"tower. While farther up on the mountain, on a small "
			"plateau, is a crumbling watch tower. ",
		({"guard tower", "tower" }) : "A large circular tower at the "
			"corner of the intersecting west and south walls of the "
			"fortress. It rises a story above the rampart, with the "
			"banner of the Gorithim flying a flag pole at its top. ",
		({"small stair", "stair", "staircase" }) : "A small, worn, stair "
			"of cut stone blocks leads up from the edge of the road to "
			"the top of the wall.",
		"road" : "The cobblestone road ends at the edge of the wall, and "
			"continues the other direction, off to the east, towards "
			"the center of the town. ",
		"valley" : "Far far below to the south is the valley "
			"that runs from east to west along the southern spur "
			"of the Frostmarches.",
		({ "mountain", "mountain side", "mountainside" }) : "The "
			"mountain looms above, the upper pinnicles covered with "
			"deep snow.",
		({"banner", "banner of the gorithim", "gorithim banner"}) :
			"The banner is a simple device, depicting a a sword and "
			"battle axe crossed over a shield with a snowcapped "
			"mountain painted on it.",
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
			"buisiness being done in the night time.");
		AddItem(({"durgoroth arena", "arena"}), "It's massive circular "
			"structure dwarfing the tavern across the way. The loud "
			"sounds of boo's and cheers come from within, with an "
			"occasional loud clang of a sword striking a shield with "
			"great force.");
		}
	SetExits( ([
		"north" : D_ROOM+"/wall01",
		"south" : D_ROOM+"/wall03",
		"down" : D_ROOM+"/road04",
		]) );
	if(query_night())
		SetListen( ([
			"default" : "The sounds of raucous drunken merry making drifts "
				"up from the tavern.",
		]) );
	else
		SetListen( ([
			"default" : "The loud sounds of \"Boo's\" and cheers come from "
				"the arena, with an occasional loud clang of a weapon "
				"striking a shield.",
		]) );
	}
