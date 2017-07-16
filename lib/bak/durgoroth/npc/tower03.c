// Title: Durgoroth Town
// File: tower03.c
// Author: Tim Morris aka Morgoth@Haven
// Date: February 1998
//
// Abstract: A crumbling watch tower above the town
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("Inside a crumbling watch tower");
	SetDayLong("Inside the crumbling walls of what was once a "
						 "watch tower the roof has caved in, leaving an open "
						 "view of the sky above. The walls are grown over with moss "
						 "and vines, and the rotten wooden door hangs ajar.");
	SetNightLong("Inside the crumblin walls of what was once a "
							 "watch tower the roof has caved in, leaving an open "
							 "view of the stars above. The walls are grown over with "
						   "moss and vines, and the rotten wooden door hangs ajar.");
	SetObviousExits("out");
	SetClimate("temperate");
	SetItems( ([
		({"crumbling walls","crumbling watch tower","walls",
		"watch tower","roof"}) : "The crumbling circular walls "
			"are all that remains of what was once a watch tower. "
			"The wooden supports of the floor above have long since "
			"rotted away causing what was above to collapse inward.",
		({"moss","vines"}) : "Moss and vines cover the stone walls "
			"of the tower.",
		({"rotten wooden door","wooden door","rotten door","door"}) :
			"The rotten, heavy, wooden door leans ajar against the "
			"of the doorway.",
		]) );
	SetExits( ([
		"out" : D_ROOM + "/wall17",
		]) );
	}
