// Title: Durgoroth Town
// File: road11.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1997
// Abstract: North-south road near the center of Durgoroth town
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("to the north of the center of Durgoroth");
	SetDayLong("This road continues up the edge of the steep "
		"mountain slope to the north, and into the square at the "
		"center of the town to the south. To the west stands the "
		"huge structure that houses the indoor market of "
		"Durgoroth. To the north a small cave opening can be seen "
		"in the mountain side at the end of the road.");
	SetNightLong("This road continues into the darkness to the "
		"north and south. To the west stands the huge black form "
		"of the indoor market of Durgoroth. To the north, a small "
		"cave opening can be seen in the mountain side at the end "
		"of the road. Barely more then a deeper black in the "
		"darkness of the night.");
	SetObviousExits("north, south");
	SetClimate("sub-arctic");
	SetDomain("FrostMarches");
	SetItems( ([
		({ "main road", "road" }) : "The main road of Durgoroth "
			"leads from the gates north to the edge of the steep "
			"mountain side.",
		({"mountain", "mountain side", "mountainside" })  : 
			"The mountain looms above, the upper pinnicles covered "
			"with deep snow.",
		({"center of town", "center", "square", "town square" 
			}) : "At the center of the town is a square formed "
			"by the intersection of the east-west road, and the "
			"north-south road. In its middle is the ancient fountain "
			"of the town.",
		({"marketplace", "market", "indoor market", "indoor marketplace"
			}) : "The huge wooden building houses the workshops and "
			"shops of the town's craftsmen and artistans.",
		({"cave opening", "cave", "small cave"}) : "A small, dark, cave "
			"opening at the end of the road in the mountain side to "
			"the north. Not much else can be seen from this distance.",
		]) );
	SetExits( ([
		"north" : D_ROOM+"/road12",
		"south" : D_ROOM+"/road07",
		]) );
	SetEnters( ([
		"market" : D_ROOM+"/market",
		]) );
	}
