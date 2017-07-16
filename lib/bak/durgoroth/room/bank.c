// Title: Durgoroth Town
// File: bank.c
// Author: Tim Morris aka Morgoth@Haven
// Date: February 1998
//
// Abstract: Durgoroth town bank
//
// Revision History: 
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("Durgoroth bank");
	SetLong("This large stone room is filled with wealthy buisinessmen "
		"and money-changers. The bank's manager usually stands "
		"behind a large polished wood counter at the end of the room, "
		"attending to customers needs.");
	SetClimate("indoors");
	SetDomain("FrostMarches");
	SetAmbientLight(35);
	SetObviousExits("out");
	SetItems( ([
		({"large stone room", "large room", "stone room",
		"durgoroth bank","bank" }) : (: GetLong :),
		({ "wealthy buisinessmen", "buisinessmen", "money-changers",
		"money changers" }) : "A large number of finely dressed "
			"buisinessmen quibble about various matters of money.",
		({ "large polished wood counter","largewood counter",
		"polished wood counter","large counter","polished counter",
		"wood counter","counter" }) : "A large polished wood counter "
			"stretches between two walls at one end of the room. "
			"Behind the counter is where the bank's employess do "
			"their work.",
		]) );
	SetExits( ([
		"out" : D_ROOM + "/road09",
		]) );
	SetInventory( ([
		D_NPC + "/narya" : 1,
		]) );
	}
