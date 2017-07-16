// Title: Durgoroth Town
// File: road08.c
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
	SetShort("to the east of the center of Durgoroth");
	SetDayLong("This road continues to the east towards the "
		"east wall of the fortress. Directly to the west "
		"is the central square of the town. To the northeast "
		"is the Durgoroth post office, and to the southeast "
		"is the Durgoroth bank.");
	SetNightLong("This road continues off into the shadows "
		"to the east and west. To the northeast is the "
		"Durgoroth post office, and to the southeast is the "
		"Durgoroth bank.");
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
		({"durgoroth post office", "post office", "office" }) :
			"The small stone building houses the post office "
			"of the town, where its citizens can send and "
			"recieve mail.",
		({"durgoroth bank", "bank" }) : "The large imposing stone "
			"building houses the Durgoroth bank, where the "
			"citizens of the town can deposit and exchange their "
			"coins.",
		]) );
	SetExits( ([
		"east" : D_ROOM+"/road09",
		"west" : D_ROOM+"/road07",
		]) );
	}
