// Title: Durgoroth Town
// File: wall08.c
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
	SetDayLong("This wall continues to the east and west. "
		"The main road of the town runs under the wall directly "
		"below, and continues to the north into the town, and to "
		"the south down into the valley. To the north a large stair "
		"leads down to the road below. To the northeast the Black "
		"Sun inn can be seen. On the southern edge of the wall "
		"is a large collection of pikes in brackets, each with a "
		"gory head or a bleached skull impaled on it.");
	SetNightLong("This wall of the fortress continues "
		"off into the darkness to the east and west. The main "
		"road of the town runs under the wall directly below, and "
		"continues to the north into the town, and to the south "
		"down into the inky blackness. To the north a large stair "
		"leads down to the road below. To the northeast the Black "
		"Sun inn can be seen, its windows glowing brightly in the "
		"chill night. On the southern edge of the wall is a large "
		"collection of pikes in brackets, each with a gory head "
		"or bleached skull impaled on it.");
	SetObviousExits("east, west, down");
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
		({ "pike", "pikes", "head", "heads", "skull", "skulls" }) : "A "
			"rather large number of heads and skulls of various races "
			"are impaled on pikes sticking from the ramparts."
			"Slain enemies of the residents of the town no doubt.",
		({"large stair","stair"}) : "A large, worn, stone stair leads "
			"from near the gate, up the wall to its top.",
		]) );
	SetExits( ([
		"east" : D_ROOM+"/wall09",
		"west" : D_ROOM+"/wall07",
		"down" : D_ROOM+"/road03",
		]) );
	SetInventory( ([
		D_NPC+"/agburnar" : 1,
		]) );
	if(query_night())
		SetListen( ([
			"default" : "The eerie call of a lone wolf drifts out "
				"of the darkness.",
		]) );
	}
