// Title: Durgoroth Town
// File: wall17.c
// Author: Tim Morris aka Morgoth@Haven
// Date: January 1998
// Abstract: A large plateau above Durgoroth
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("small plateau above Durgoroth");
	SetDayLong("This plateau is larger then it seemed from below. "
		"At the northwestern corner of the plateau is the "
		"small crumbling watch tower. While to the north is the "
		"Durgoroth cemetery. To the southeast a narrow winding "
		"stairway snakes its way back down to the town far below. "
		"The town and fortress of Durgoroth are spread out below, "
		"while the mountain drops away below the town far down "
		"into the valley below.");
	SetNightLong("This plateau is larger then it seemed from below. "
		"To the northeast is the dim form of a small crumbling watch "
		"tower. To the north, extending off into the darkness, is the "
		"Durgoroth cemetery. To the southeast a narrow winding "
		"stairway snakes its way back down into the darkness. "
		"Far below the faint lights of the town twinkle in the "
		"darkness.");
	SetObviousExits("north, down, tower");
	SetClimate("sub-arctic");
	SetDomain("FrostMarches");
	SetItems( ([
		({"narrow stairway","winding stairway","stairway","stair" }) :
			"The narrow, winding, worn stone stairway snakes down from "
			"the plateau to the eastern wall of the fortress far "
			"below.",
		({"eastern wall","wall","walls","fortress"}) : "The fortress "
			"of Durgoroth can be seen below, its three walls "
			"enclosing the town in a large rectangle between the "
			"walls and the mountain side. The stairway winds down "
			"to connect with the eastern wall of the fortress far "
			"below.",
		({"small crumbling watch tower","crumbling watch tower",
		"small watch tower","small tower","crumbling tower",
		"watch tower","tower"}) : "A small crumbling watch tower "
			"is perched near the edge of the plateau to the "
			"northwest. Its turret is crumbling, and large creeping "
			"vines climb up its sides, a rotten wooden door hangs "
			"half open, beyond are deep shadows.",
		({"small plateau","plateau"}) : "The plateau is larger then "
			"it seemed from below. To the north is the Durgoroth "
			"cemtery, while to the northwest stands a small "
			"crumbling watch tower.",
		({"mountain", "mountain side", "mountainside" }) : "The "
			"mountain looms above, the upper pinnicles covered with "
			"deep snow.",
		({ "fortress", "durgoroth", "town", "fortress town",
		"durgoroth town", "durgoroth fortress" }) : "The massive, "
			"slightly crumbling stone walls and towers of the "
			"fortress spread out below. Its huge rectangular form "
			"sticking out like a sore thumb in the wilderness to "
			"all sides.",
		"valley" : "Far far below to the south is the valley "
			"that runs from east to west along the southern spur "
			"of the Frostmarches.",
		]) );
	SetExits( ([
		"north" : D_ROOM+"/cemetery",
		"down" : D_ROOM+"/wall16",
		]) );
	SetEnters( ([
		"tower" : D_ROOM+"/tower03",
		]) );
	if(query_night())
		SetListen( ([
			"default" : "The eerie call of a lone wolf drifts out "
				"of the darkness.",
		]) );
	else
		SetListen( ([
			"default" : "The call of a raven echoes in the quiet "
				"mountain air.",
		]) );
	}
