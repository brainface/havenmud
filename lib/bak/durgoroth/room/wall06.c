// Title: Durgoroth Town
// File: wall06.c
// Author: Tim Morris aka Morgoth@Haven
// Date: January 1998
// Abstract: Southern wall of the Durgoroth town
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
	SetDayLong("This wall continues to the east and west. To the "
		"west it joins with the southwestern guard tower of the "
		"fortress. To the south the mountain falls away, down into "
		"the valley far below. To the northeast the back of the "
		"infamous Raunchy Goblin Tavern can be seen. While to the "
		"northeast the rear of the Black Sun inn is also in view.");
	SetNightLong("This wall continues into the darkness to the east "
		"and west. On the other side of the wall lies a sea of "
		"blackness where the mountain drops away, down to the "
		"valley below. To the northwest the back of the Raunchy "
		"Goblin Tavern can be seen, its windows shining out like "
		"beacons in the night. While to the northeast the the rear "
		"of the Black Sun inn is also in view, its warmly lit "
		"windows similarly welcoming.");
	SetObviousExits("east, west");
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
			"banner of the Gorithim flying from a flag pole at its top. ",
		"valley" : "Far far below to the south is the valley "
			"that runs from east to west along the southern spur "
			"of the Frostmarches.",
		({ "black sun inn", "black sun", "inn" }) : "The Black Sun "
			"inn is a large, two story, wood and stone block "
			"building. Smoke pours from the chimney at the back "
			"of the building, where the kitchen must be. Travellers "
			"are always welcome, if they have the coins to pay for "
			"their stay. ",
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
		"east" : D_ROOM+"/wall07",
		"west" : D_ROOM+"/wall05",
		]) );
	}
