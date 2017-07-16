// Title: Durgoroth Town
// File: road01.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1997
//
// Abstract: Road just outside of the town gates
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

int PreExit();

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("outside the gates of Durgoroth");
	SetDayLong("This road continues down to the south.  To the "
		"north stands the hulking form of the fortress town "
		"Durgoroth, its decaying, rough cut stone walls and "
		"towers standing out in relief against the "
		"glimmering white of the mountain. Directly to the "
		"north are the gates to the town.");
	SetNightLong("This road continues down to the south.  To the "
		"north stands the hulking form of the fortress town "
		"Durgoroth.  In the darkness it looks like a huge "
		"dark monster sleeping in a fold of the mountain "
		"side. Directly to the north are the gates to the "
		"town.  They are normally kept closed now to keep "
		"criminals and vagabonds out of the town.");
	SetObviousExits("north, south");
	SetClimate("sub-arctic");
	SetDomain("FrostMarches");
	SetItems( ([
		({ "crystal mountains","crystal mountain" }) :
			"From this point none of the mountain range "
			"can be seen except the one you now stand on.",
		({"mountain road","road","path"}) : "The mountain "
			"road continues down into the valley below.",
		"valley" : "Far far below to the south is the valley "
			"that runs from east to west along the sothern spur "
			"of the Frostmarches.",
		({"fortress", "town", "city", "durgoroth", "Durgoroth",
			"fortress town"}) :
			"The walls and towers of the fortress town "
			"can be seen clearly to the north, standing out in "
			"relief against the snow of the mountain. It is "
			"nestled into a hollow in the mountain side, with "
			"its eastern and western walls connecting directly "
			"with the steep mountain side. "
			"The fortress is rumoured to have been built sometime "
			"during the God's War, but is currently inhabited "
			"by a rough colony of humans.",
		({"stone wall","stone walls","wall","eastern wall",
			"western wall","main wall"}) :
			"The thick stone walls of Durgoroth "
			"were built long ago by an unknown force, but "
			"appear strong enough to withstand any attack.",
		({"tower","towers"}) : "There are two guard towers, "
			"one at each end of the main wall of Durgoroth, "
			"and further up the mountain, above the town, is "
			"a decaying stone watch tower.",
		({"guard tower", "guard towers"}) : "Two guard "
			"towers, one at each end of the main wall of "
			"Durgoroth.",
		({ "stone watch tower","watch tower" }) :
			"A decaying stone watch tower can be seen on the "
			"mountain above the town.",
		({ "mountain side", "mountainside", "mountain", "pinnacle"
			"snow" }) :
			"The mountain looms above, the upper pinnacle "
			"covered with deep snow.",
		({ "gate", "gates","oak door","oak doors" }) :
			"The gates to Durgoroth "
			"are a massive set of oak doors.  Little detail "
			"can be seen from this distance.",
		({ "hollow" }) : "A fold in the mountain, into which is "
			"nestled the fortress of Durgoroth.",
		]) );
	SetExits( ([
		"north" : D_ROOM + "/road02",
		]) );
	AddExit("south",
        "/domains/frostmarches/virtual/durgorothroad/-10,15", (: PreExit :));
	}

int PreExit() {
	if( this_player()->GetProperty("durgorothNPC"))
		return 0;
	else
		return 1;
	}
