// Title: Durgoroth Town
// File: wall09.c
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
		"the east and west. To the west are the gates of the "
		"fortress, which the walls pass over. The main road of the "
		"town runs up from the valley, and through the gates under "
		"the wall, into the town. On the other side of the wall, "
		"to the south, the mountain drops away down into the "
		"valley below. To the northeast the back of the "
		"Durgoroth bank can be seen.");
	SetNightLong("This is the southern wall of the fortress, it "
		"continues off "
		"into the darkness to the east and west. To the west "
		"are the gates of the fortress, which the walls pass over. "
		"The main road of town runs up from the valley, and "
		"through the gates under the wall, into the town. On the "
		"the other side of the wall lies a sea of darkness, where "
		"the mountain drops away down into the valley far below. "
		"To the northeast the back of the Durgoroth can dimly be "
		"seen in the darkness.");
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
		({"fortress gate", "fortress gates", "gate", "gates"}) :
			"To the east the wall passes over the gates of "
			"the fortress. Through which the main road runs, "
			"under the ramparts and into the town.",
		({"road", "main road"}) : "The main road of the town "
			"runs under the ramparts, through the gate, and on "
			"into the town. While to the other direction it runs "
			"through a series of switchbacks down into the valley "
			"far below.",
		({ "rampart", "ramparts" }) : "The rampart runs along the top "
			"of the wall between the towers and the mountain-side. The "
			"eastern rampart joins a stair leading up to the watch tower "
			"higher up on the mountain.",
		({"fortress", "town", "city", "durgoroth", "Durgoroth"}) :
			"The town is nestled into a hollow in the mountain "
			"side, with its eastern and western walls connecting "
			"directly with the steep mountain side. "
			"The fortress is rumoured to have been built sometime "
			"during the God's War, but is currently inhabited "
			"by a rough colony of humans.",
		({"durgoroth bank", "bank" }) : "The large imposing stone "
			"building houses the Durgoroth bank, where the "
			"citizens of the town can deposit and exchange their "
			"coins.",
		({ "mountain", "mountain side", "mountainside" }) : "The "
			"mountain looms above, the upper pinnicles covered with "
			"deep snow.",
		]) );
	SetExits( ([
		"east" : D_ROOM+"/wall10",
		"west" : D_ROOM+"/wall08",
		]) );
	}
