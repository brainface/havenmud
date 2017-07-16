// Title: Durgoroth Town
// File: cave05.c
// Author: Timothy Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: Private room for the clerics and cavaliers of Saa'HaGoth
//
// Revision History: 
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
    SetTown("Durgoroth");
	SetShort("private room");
	SetLong("A private room where the faithful of Saa'HaGoth "
		"can relax and post notes for each other. There are "
		"several stone benches, as well as a small fireplace "
		"with a fire in it.");
	SetObviousExits("west");
	SetClimate("indoors");
  SetProperty("no magic", 1);
	SetDomain("FrostMarches");
	SetAmbientLight(30);
	SetItems( ([
		({"bench","benches"}) : "Large stone benches set against "
			"the walls of the room.",
		({"fire","fireplace"}) : "A small fireplace set in "
			"the wall of the room. Burning brightly.",
		]) );
	SetItemAdjectives( ([
		"bench" : "stone",
		"fire" : "small",
		]) );
	SetExits( ([
		"west" : D_ROOM + "/cave02",
		]) );
        SetNewsgroups( ({ "religion.saahagoth" }) );
	SetInventory( ([
		]) );
	SetProperty("no attack", 1);
	SetProperty("no bump", 1);
	SetProperty("no teleport", 1);
	}
