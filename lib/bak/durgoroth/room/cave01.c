// Title: Durgoroth Town
// File: cave01.c
// Author: Timothy Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: Entrance to the cave in Durgoroth town
//
// Revision History: 
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
    SetTown("Durgoroth");
	SetShort("inside a small cave");
	SetLong("To the south the cave opens up onto the town. "
		"While to the north a narrow tunnel curves around "
		"and down into the darkness to the northwest. The air "
		"here is cool and dry, the way Nosferatu like it.");
	SetObviousExits("northwest, out");
	SetClimate("indoors");
	SetDomain("FrostMarches");
	SetAmbientLight(30);
	SetItems( ([
		({"cave","small cave"}) : (: GetLong :),
		({"narrow tunnel","tunnel"}) : "The narrow tunnel "
			"slopes gently down into the darkness, and follows "
			"a curve around to the northwest.",
		]) );
	SetExits( ([
		"northwest" : D_ROOM + "/cave02",
		"out" : D_ROOM + "/road12",
		]) );
	}
