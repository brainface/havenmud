// Title: Durgoroth Town
// File: road07.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1997
// Abstract: Central intersection of Durgoroth town
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("central intersection of Durgoroth");
	SetDayLong("The main road of Durgoroth continues up to the edge of "
		"the steep mountain side to the north, and to the gates of the "
		"fortress to the south. While the other road runs off "
		"to the east and west towards the walls of the fortress. "
		"In the center of the square is the ancient fountain. To the "
		"northwest is the huge indoor marketplace of Durgoroth, and to "
		"the south the Dark Sun inn can be seen.");
	SetNightLong("The main road of Durgoroth continues off into the "
		"darkness to the north and south. While the other road runs off "
		"to the east and west. In the center of the square is the ancient "
		"fountain. To the northwest is the huge black shape of the indoor "
		"marketplace of Durgoroth. While to the south  faint glow of the "
		"windows of the Dark Sun inn can be seen.");
	SetObviousExits("north, south, east, west");
	SetClimate("sub-arctic");
	SetDomain("FrostMarches");
	SetItems( ([
		({"road", "roads", "main road"}) : "The main road of Durgoroth "
			"runs from the north to the south, towards the mountain side "
			"to the north, and the gates of the fortress to the south. "
			"The intersecting road runs off to the east and west towards "
			"the walls of the fortress.",
		({ "mountain", "mountain side", "mountainside" }) : "The mountain "
			"looms above, the upper pinnicles covered with deep snow.",
		({ "gate", "gates", "fortress gates", "fortress gate" }) : "The "
			"gates of the fortress are to the south, but are too far off "
			"to see much of their details.",
		({"center of town", "center", "square", "town square" 
			}) : "At the center of the town is a square formed "
			"by the intersection of the east-west road, and the "
			"north-south road. In its middle is the ancient fountain "
			"of the town.",
		({ "fortress", "durgoroth" }) : "The huge fortress "
			"completely encloses the large town, with massive walls that "
			"surround it up to the edge of the steep mountain side.",
		({"marketplace", "market", "indoor market", "indoor marketplace"
			}) : "The huge wooden building houses the workshops and "
			"shops of the town's craftsmen and artistans.",
		({ "black sun inn", "black sun", "inn" }) : "The Black Sun inn "
			"is a large, two story, wood and stone block building. "
			"Travellers are always welcome, if they have the coins to "
			"pay for their stay. ",
		]) );
	SetExits( ([
		"north" : D_ROOM+"/road11",
		"south" : D_ROOM+"/road03",
		"east" : D_ROOM+"/road08",
		"west" : D_ROOM+"/road06",
		]) );
	SetEnters( ([
		"market" : D_ROOM+"/market",
		]) );
	SetInventory( ([
		D_NPC+"/guard3" : 1,
		D_NPC+"/guard4" : 1,
		D_OBJ+"/fountain" : 1,
		]) );
	}
