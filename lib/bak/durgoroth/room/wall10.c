// Title: Durgoroth Town
// File: wall10.c
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
	SetDayLong("This is the southern wall of the fortress, it "
		"continues to "
		"the east and west. To the east it joins with the "
		"southeastern guard tower of the fortress. On the other "
		"side of the wall, to the south, the mountain falls away, "
		"down into the valley far below. To the north the back of "
		"the Durgoroth bank can be seen.");
	SetNightLong("This is the southern wall of the fortress, it "
		"continues off "
		"into the darkness to the east and west. To the east it "
		"joins with the southeastern guard tower of the fortress. "
		"On the other side of the wall, to the south, lies a sea "
		"of darkness where the mountain drops away down into the "
		"valley. To the north the dim form of the Durgoroth "
		"bank can be seen.");
	SetObviousExits("east, west");
	SetClimate("sub-arctic");
	SetDomain("FrostMarches");
	SetItems( ([
		({ "wall", "walls","towers", "fortress" }) : "The massive "
			"walls of ancient, weather worn black stone surround the "
			"town. At each corner of the main wall is a large guard "
			"tower. While farther up on the mountain, on a small "
			"plateau, is a crumbling watch tower. ",
		"valley" : "Far far below to the south is the valley "
			"that runs from east to west along the southern spur "
			"of the Frostmarches.",
		({"guard tower", "tower" }) : "A large circular tower at the "
			"corner of the intersecting west and south walls of the "
			"fortress. It rises a story above the rampart, with the "
			"banner of the Crusade flying from a flag pole at its top. ",
		({"banner of the crusade", "crusade banner", "banner"}) :
			"The banner is an intracite depiction of the angel of "
			"death, bearing a huge two handed sword, decending to "
			"reap the souls of the innocent.",
		({ "mountain", "mountain side", "mountainside" }) : "The "
			"mountain looms above, the upper pinnicles covered with "
			"deep snow.",
		({"durgoroth bank", "bank" }) : "The large imposing stone "
			"building houses the Durgoroth bank, where the "
			"citizens of the town can deposit and exchange their "
			"coins.",
		]) );
	SetExits( ([
		"east" : D_ROOM+"/wall11",
		"west" : D_ROOM+"/wall09",
		]) );
	}
