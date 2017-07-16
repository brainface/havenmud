// Title: Durgoroth Town
// File: road06.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1997
// Abstract: East-west road near the center of Durgoroth town
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("to the west of the center of Durgoroth");
	SetDayLong("This road continues to the west towards the "
		"western wall of the town. To the east is the center "
		"of the town. To the north is the huge indoor "
		"marketplace of Durgoroth.");
	SetNightLong("This road continues into the shadows to "
		"the west, and into the moonlit square at the center "
		"of the town to the east. To the north is the huge "
		"black shape of Durgoroth's indoor marketplace.");
	SetObviousExits("east, west");
	SetClimate("sub-arctic");
	SetDomain("FrostMarches");
	SetItems( ([
		"road" : "The cobblestone road runs from the east wall "
			"through the center of the town, to the west wall.",
		({"center of town", "center", "square", "town square" 
			}) : "At the center of the town is a square formed "
			"by the intersection of the east-west road, and the "
			"north-south road.",
		({"marketplace", "market", "indoor market", "indoor marketplace"
			}) : "The huge wooden building houses the workshops and "
			"stores of the town's craftsmen and artistans.",
		]) );
	SetExits( ([
		"east" : D_ROOM+"/road07",
		"west" : D_ROOM+"/road05",
		]) );
	SetEnters( ([
		"market" : D_ROOM+"/market",
		]) );
	}
