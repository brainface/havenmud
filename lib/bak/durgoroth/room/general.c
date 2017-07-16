// Title: Durgoroth Town
// File: general.c
// Author: Tim Morris aka Morgoth@Haven
// Date: February 1998
//
// Abstract: Mavok's General Store in Durgoroth
//
// Revision History: 
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
    SetTown("Durgoroth");
	SetShort("Mavox's General Store");
	SetLong("This is a neat, organized shop owned by Mavox. "
		"There are many items of different types, shapes "
		"and colors stacked neatly on the shelves.");
	SetAmbientLight(35);
	SetClimate("indoors");
	SetDomain("FrostMarches");
	SetObviousExits("out");
	SetItems( ([
		({"neat shop","organized shop","shop","general store"}) :
			(: GetLong :),
		({"items","shelves","item","shelf"}) : "There are many "
			"items of types and descriptions so numerous it "
			"boggles the mind.",
		]) );
	SetExits( ([
		"out" : D_ROOM + "/market",
		]) );
	SetInventory( ([
		D_NPC + "/mavox" : 1,
		]) );
	}

