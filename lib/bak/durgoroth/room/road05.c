// Title: Durgoroth Town
// File: road05.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1997
// Abstract: East-west road inside the town of Durgoroth
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("east west road in Durgoroth");
	SetDayLong("This road continues to the edge of the western wall to "
		"the west. And towards the center of the town to the east. "
		"To the northwest stands the large structure of the Durgoroth "
		"arena. Its massive circular structure dwarfing the other "
		"buildings nearby. To the southwest is the infamous Raunchy "
		"Goblin tavern. To the northeast is the huge indoor "
       "marketplace of Durgoroth.  A small house stands to the south.");
	SetNightLong("This road continues towards the black form of the "
		"western wall. And off into the shadows into the east. "
		"To the northwest stands the now quiet arena. Its massive "
		"circular structure blocking out an entire quadrant of "
		"stars. To the southwest is the infamous Raunchy Goblin "
		"tavern. To the northeast is the form of the huge indoor "
       "marketplace of Durgoroth.  A small house stands alone on "
       "the south side of the street.");
	SetObviousExits("east, west");
	SetClimate("sub-arctic");
	SetDomain("FrostMarches");
	SetItems( ([
                ({"house"}) : "This is a nice looking house.",
		({"western wall", "wall"}) : "The massive walls of ancient, "
			"weather worn black stone surround the town.",
		"road" : "The cobblestone road ends at the edge of the wall to "
			"the east, and continues the other direction, off to the "
			"east, towards the center of the town. ",
		({"marketplace", "market", "indoor market", "indoor marketplace"
			}) : "The huge wooden building houses the workshops and "
			"stores of the town's craftsmen and artistans.",
		]) );
		if(query_night()) {
		AddItem(({"raunchy goblin tavern", "raunchy goblin", "tavern"}),
			"The large wooden structure leans up against the wall. "
			"The windows shine out like a beacon in the cold night. "
			"The raucous sounds of drunken merry making drift out "
			"into the quiet night street. ");
		AddItem(({"durgoroth arena", "arena"}), "The massive circular "
			"structure blocks out an entire quadrent of the stars, "
			"dwarfing the structures next door and across the street. ");
			}
		else {
		AddItem(({"raunchy goblin tavern", "raunchy goblin", "tavern"}),
			"The large wooden structure leans up against the wall. "
			"The tavern's windows are dark now, the majority of its "
			"buisiness being done in the night time.");
		AddItem(({"durgoroth arena", "arena"}), "It's massive circular "
			"structure dwarfing the tavern across the way. The loud "
			"sounds of \"Boo's\" and cheers come from within, with an "
			"occasional loud clang of a sword striking a shield with "
			"great force.");
		}
	SetExits( ([
		"east" : D_ROOM+"/road06",
		"west" : D_ROOM+"/road04",
		]) );
    SetEnters( ([
              "house"          : D_ROOM + "/p_house_1" ,
]));
}
