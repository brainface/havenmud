// Title: Durgoroth Town
// File: road12.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1997
// Abstract: North-south road inside the town of Durgoroth
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("near a cave at the north end of the road");
	SetDayLong("The road ends at the mouth of a cave here, but "
		"continues into the town to the south. To the southwest "
		"the huge structure that houses the indoor marketplace "
		"of Durgoroth can be seen. Directly to the north is "
		"the mouth of the cave. Little can be seen inside "
		"other then a small tunnel leading down and north.");
	SetNightLong("The road ends at the mouth of a small cave "
		"here, but continues into the darkness to the south. "
		"To the southwest lies the huge black form of the "
		"building that houses the indoor market of Durgoroth. "
		"Directly to the north is the mouth of the cave, in "
		"the darkness of the night, nothing can be seen of the "
		"interior.");
	SetObviousExits("south");
	SetClimate("sub-arctic");
	SetDomain("FrostMarches");
	SetItems( ([
		({ "main road", "road" }) : "The main road of Durgoroth "
			"leads from the gates north to the edge of the steep "
			"mountain side.",
		({"mountain", "mountain side", "mountainside" })  : 
			"The mountain looms above, the upper pinnicles covered "
			"with deep snow.",
		({"marketplace", "market", "indoor market", "indoor marketplace"
			}) : "The huge wooden building houses the workshops and "
			"shops of the town's craftsmen and artistans.",
		({ "cave", "small cave", "cave mouth", "small cave mouth" }) :
			"A small cave in the side of the mountain to the north. "
			"Little can be seen inside other then a small tunnel "
			"leading down and north.",
		]) );
	SetExits( ([
		"south" : D_ROOM+"/road11",
		]) );
	SetEnters( ([
		"cave" : D_ROOM+"/cave01",
		]) );
	}
