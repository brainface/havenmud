// Title: Durgoroth Town
// File: wall15.c
// Author: Tim Morris aka Morgoth@Haven
// Date: January 1998
// Abstract: Northeastern corner of the Durgoroth town wall
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("northeastern corner of the wall");
	SetDayLong("This is the eastern wall of the fortress, it ends "
		"against the "
		"steep mountain side here, but continues off to the south. "
		"A narrow winding stairway leads up from the end of the wall "
		"to a small plateau far above. On the other side of the "
		"wall, to the east, the mountain falls away down into the "
		"valley below. To the east the columned structure that is "
		"the Durgoroth library can be seen.");
	SetNightLong("This is the eastern wall of the fortress, it ends "
		"against the "
		"steep mountain side here, but continues off into the "
		"darkness to the south. A narrow winding stairway leads up "
		"from the end of the wall to a small plateau far above. "
		"On the other side of the wall, to the east, lies a sea "
		"of blackness where the mountain falls away down into the "
		"valley far below. To the east the large black form of the "
		"Durgoroth library can be seen.");
	SetObviousExits("south, up");
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
		({ "mountain", "mountain side", "mountainside" }) : "The "
			"mountain looms above, the upper pinnicles covered with "
			"deep snow.",
		({"durgoroth library", "library","columned structure" }) : 
			"The large ornate stone edifice "
			"houses the knowledge of the town, as well as a few "
			"carefully guarded tomes from the previous inhabitants "
			"of the fortress. It is also the place from which "
			"many of the town's scholars do buisiness.",
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
		"south" : D_ROOM+"/wall14",
		"up" : D_ROOM+"/wall16",
		]) );
	}
