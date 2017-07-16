// Title: Durgoroth Town
// File: wall07.c
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
		"continues to the "
		"east and west. To the east is the gates of the fortress, "
		"over which the wall passes. On the other side of the wall, "
		"to the south, the mountain falls away, down into the valley "
		"below. To the north the Black Sun inn can be seen.");
	SetNightLong("This is the southern wall of the fortress, it "
		"continues off "
		"into the darkness to the east and west. On the other side "
		"of the wall, to the south, is a sea of darkness where "
		"the mountain drops away down into the valley far below. To "
		"the north the Black Sun inn can be seen, its windows "
		"glowing welcomingly in the dark night.");
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
		({ "black sun inn", "black sun", "inn" }) : "The Black Sun "
			"inn is a large, two story, wood and stone block "
			"building. Smoke pours from the chimney at the back "
			"of the building, where the kitchen must be. Travellers "
			"are always welcome, if they have the coins to pay for "
			"their stay. ",
		({"fortress gate", "fortress gates", "gate", "gates"}) :
			"To the east the wall passes over the gates of "
			"the fortress. Through which the main road runs, "
			"under the ramparts and into the town.",
		({"road", "main road"}) : "The main road of the town "
			"runs under the ramparts, through the gate, and on "
			"into the town.",
		({ "rampart", "ramparts" }) : "The rampart runs along the top "
			"of the wall between the towers and the mountain-side. The "
			"eastern rampart joins a stair leading up to the watch tower "
			"higher up on the mountain.",
		({ "mountain", "mountain side", "mountainside" }) : "The "
			"mountain looms above, the upper pinnicles covered with "
			"deep snow.",
		]) );
	SetExits( ([
		"east" : D_ROOM+"/wall08",
		"west" : D_ROOM+"/wall06",
		]) );
	}
