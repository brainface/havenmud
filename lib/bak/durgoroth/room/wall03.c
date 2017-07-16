// Title: Durgoroth Town
// File: wall03.c
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
	SetDayLong("This is the western wall, it ends at the "
		"southwestern guard "
		"tower here, but it continues to the north toward the "
		"mountain side. On the other side of the wall, to the west, "
		"the mountain falls away, down into the valley far below, while "
		"to the north it rises up to incomprehendable heights. "
		"To the south is the large circular guard "
		"tower that stands at the intersection of the western and "
		"southern walls of the fortress. To the east is the "
		"Raunchy Goblin tavern.");
	SetNightLong("This the western wall, it ends at the "
		"southwestern guard "
		"tower here, but it continues off into the darkness to the north. "
		"On the other side of the wall, to the west, lies a sea of "
		"blackness where the mountain drops away into the valley. Directly "
		"to the south is the large circular guard tower that stands at the "
		"intersection of the western and southern walls of the fortress. "
		"And to the east is the Raunchy Goblin tavern, its windows "
		"shining out like beacons in the cold night.");
	SetObviousExits("north, tower");
	SetClimate("sub-arctic");
	SetDomain("FrostMarches");
	SetItems( ([
		({ "wall", "walls","towers", "fortress" }) : "The massive "
			"walls of ancient, weather worn black stone surround the "
			"town. At each corner of the main wall is a large guard "
			"tower. While farther up on the mountain, on a small "
			"plateau, is a crumbling watch tower. ",
		({"guard tower", "tower" }) : "A large circular tower at the "
			"corner of the intersecting western and southern walls of "
			"the fortress. It rises a story above the rampart, with "
			"the banner of the Gorithim rising from its top. A small "
			"wooden door grants access to the interior of the tower.",
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
		if(query_night())
		AddItem(({"raunchy goblin tavern", "raunchy goblin", "tavern"}),
			"The large wooden structure leans up against the wall. "
			"The windows shine out like a beacon in the cold night. "
			"The raucous sounds of drunken merry making drift out "
			"into the quiet night street. ");
		else
		AddItem(({"raunchy goblin tavern", "raunchy goblin", "tavern"}),
			"The large wooden structure leans up against the wall. "
			"The tavern's windows are dark now, the majority of its "
			"buisiness being done in the night time.");
	SetExits( ([
		"north" : D_ROOM+"/wall02",
		]) );
	SetEnters( ([
		"tower" : D_ROOM+"/wall04",
		]) );
	if(query_night())
		SetListen( ([
			"default" : "The sounds of raucous drunken merry making drifts "
				"up from the tavern.",
		]) );
	}
