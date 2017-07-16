// Title: Durgoroth Town
// File: wall05.c
// Author: Tim Morris aka Morgoth@Haven
// Date: January 1998
// Abstract: Near southwestern guard tower of the Durgoroth town
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("southern wall of Durgoroth");
	SetDayLong("This is the southern wall, it ends at the "
		"southwestern guard "
		"tower here, but it continues to the east toward the "
		"gates of the fortress. On the other side of the wall, "
		"to the south, the mountain falls away, down into the "
		"valley far below. To the west is the large circular guard "
		"tower that stands at the intersection of the western and "
		"southern walls of the fortress. To the north, the back "
		"of the Raunchy Goblin tavern can be seen.");
	SetNightLong("This is the southern wall, it ends at the "
		"southwestern guard "
		"tower here, but it continues off into the darkness to the "
		"east. On the other side of the wall, to the south, lies a "
		"sea of blackness where the mountain drops away into the "
		"valley. Directly to the west is the large circular guard "
		"tower that stands at the intersection of the western and "
		"southern walls of the fortress. And to the north the back "
		"of the Raunchy Goblin tavern can be seen, its windows "
		"shining out like beacons in the cold night.");
	SetObviousExits("east, tower");
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
		({"banner", "banner of the gorithim", "gorithim banner"}) :
			"The banner is a simple device, depicting a a sword and "
			"battle axe crossed over a shield with a snowcapped "
			"mountain painted on it.",
		({ "mountain", "mountain side", "mountainside" }) : "The "
			"mountain looms above, the upper pinnicles covered with "
			"deep snow.",
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
		"east" : D_ROOM+"/wall06",
		]) );
	SetEnters( ([
		"tower" : D_ROOM+"/wall04",
		]) );
	}
