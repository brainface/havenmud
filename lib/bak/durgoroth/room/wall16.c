// Title: Durgoroth Town
// File: wall16.c
// Author: Tim Morris aka Morgoth@Haven
// Date: January 1998
// Abstract: Stair from wall to watch tower
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("stair from wall to watch tower");
	SetDayLong("This narrow stairway takes a winding path up the "
		"mountain, snaking from the the edge of the eastern wall "
		"of the fortress up to a small crumbling watch tower on "
		"a small plateau above. The town and fortress of Durgoroth "
		"are spread out below, while the mountain drops away below "
		"the town far down into the valley below.");
	SetNightLong("This narrow stairway takes a winding path up "
		"the mountain, snaking from the edge of the eastern wall "
		"of the fortress to a small plateau above. Below, the "
		"twinkling lights of the town can be seen, and beyond, only "
		"deep darkness.");
	SetObviousExits("up, down");
	SetClimate("sub-arctic");
	SetDomain("FrostMarches");
	SetItems( ([
		({"narrow stairway","winding stairway","stairway","stair" }) :
			"The narrow, winding, worn stone stairway snakes up from "
			"the wall of the fortress to the isolated watch tower "
			"above.",
		({"eastern wall","wall","walls","fortress"}) : "The fortress "
			"of Durgoroth can be seen below, its three walls "
			"enclosing the town in a large rectangle between the "
			"walls and the mountain side. The stairway winds down "
			"to connect with the eastern wall of the fortress far "
			"below.",
		({"small crumbling watch tower","crumbling watch tower",
		"small watch tower","small tower","crumbling tower",
		"watch tower","tower"}) : "A small crumbling watch tower "
			"perched on a small plateau far above the fortress.",
		({"small plateau","plateau"}) : "A small plateau on the "
			"mountain side above.",
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
			"that runs from east to west along the crystal "
			"reaches, clear from Haven town to the western sea.",
		]) );
	SetExits( ([
		"up" : D_ROOM+"/wall17",
		"down" : D_ROOM+"/wall15",
		]) );
	if(query_night())
		SetListen( ([
			"default" : "The eerie call of a lone wolf drifts out "
				"of the darkness.",
		]) );
	}
