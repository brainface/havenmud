// Title: Durgoroth Town
// File: wall14.c
// Author: Tim Morris aka Morgoth@Haven
// Date: January 1998
// Abstract: Eastern wall of the Durgoroth town
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("east wall of Durgoroth");
	SetDayLong("This wall of the fortress continues to the north "
		"and south. To the north the wall ends against the "
		"mountain side, while to the south it joins with the "
		"southwestern guard tower of the fortress. Where the wall "
		"ends against the mountain, a narrow winding stairway "
		"leads up the mountain to a crumbling watch tower on a "
		"small plateau far above. To the east the mountain falls "
		"away, down into the valley far below, while to the north "
		"the mountain rises up to incomprehendable heights. To "
		"the west a small stair leads down from the wall to the "
		"street below. To the northwest the large columned "
		"structure of the Durgoroth library can be seen.");
	SetNightLong("This wall of the fortress continues into the "
		"darkness to the north and south. A small stair leads down "
		"from the wall to the street below. On the other side of "
		"the wall, to the east, lies a sea of blackness where the "
		"mountain drops away down to the valley, while to the north "
		"the mountain rises away into the dark night sky. A narrow "
		"winding stairway can dimly be seen climbing up the "
		"mountain to a small plateau far above. To the northwest "
		"the black form of the Durgoroth library can be seen.");
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
			"corner of the intersecting east and south walls of the "
			"fortress. It rises a story above the rampart, with the "
			"banner of the Crusade flying from a flag pole at its "
			"top. ",
		({"small stair", "stair", "staircase" }) : "A small, worn, stair "
			"of cut stone blocks leads up from the edge of the road to "
			"the top of the wall.",
		"road" : "The cobblestone road ends at the edge of the wall, and "
			"continues the other direction, off to the west, towards "
			"the center of the town. ",
		"valley" : "Far far below to the south is the valley "
			"that runs from east to west along the southern spur "
			"of the Frostmarches.",
		({ "mountain", "mountain side", "mountainside" }) : "The "
			"mountain looms above, the upper pinnicles covered with "
			"deep snow.",
		({"durgoroth library", "library","columned structure" }) : 
			"The large ornate stone edifice "
			"houses the knowledge of the town, as well as a few "
			"carefully guarded tomes from the previous inhabitants "
			"of the fortress. It is also the place from which "
			"many of the town's scholars do buisiness.",
		({"banner of the crusade", "crusade banner", "banner"}) :
			"The banner is an intracite depiction of the angel of "
			"death, bearing a huge two handed sword, decending to "
			"reap the souls of the innocent.",
		({"narrow winding stairway","winding stairway",
		"narrow stair","winding stair", "stair"}) : "A narrow and "
			"winding worn stone stairway leads up from the end of "
			"the eastern wall of the fortress to a crumbling watch "
			"tower on a small plateau far above.",
		({"small plateau","plateau"}) : "A small plataue far "
			"up on the mountain above the town.",
		({"small crumbling watch tower","watch tower","crumbling "
		"watch tower","crumbling tower","tower"}) : "A small "
			"crumbling watch tower high above the town on a small "
			"plateau.",
		]) );
	SetExits( ([
		"north" : D_ROOM+"/wall15",
		"south" : D_ROOM+"/wall13",
		"down" : D_ROOM+"/road10",
		]) );
	}
