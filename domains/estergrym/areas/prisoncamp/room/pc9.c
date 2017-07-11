#include <lib.h>
#include "../prisoncamp.h"
inherit LIB_ROOM;

static void create()
{
	room::create();
	SetShort("southeast corner of the work area");
	SetLong("A large pile of rocks are waiting here to be busted "
		"into smaller rocks.  "
		"The rocks appear to be stained with oil and blood.  "
		"Dust rises into the air with each strike of a sledge.  "
		"The taskmaster's quarters are "
		"off to the north.  The gate lies to the west.  ");
	SetClimate("underground");
	SetAmbientLight(30);
	SetExits(  ([
		"north" : P_ROOM + "pc6",
		"west" : P_ROOM + "pc8",
		"northwest" : P_ROOM + "pc5",
		])  );
	SetListen(  ([
		"default" : "The sounds of hammers clanging on rocks "
			    "the air.  "
		])  );
	SetSmell(  ([
		"default" : "Dust and oil make it hard to breathe.  ",
		])  );
	SetItems(  ([
		({ "rocks", "rock", "pile" }) : "It would take a lot of work "
			"to break these large rocks.",
		({ "taskmaster's quarters", "quarters" }) : "The taskmaster's "
			"quarters are difficult to make out from here.  ",
		"air" : "It is thick with dust",
		({ "blood", "oil" }) : "Old and new stains cover the rocks.  ",
		"dust" : "It clouds up from the rock.",
		"gate" : "It is barely discernable from here.  ",
		])  );
	SetInventory(  ([
		P_NPC "melf" : 2,
		P_NPC "guard" : 1,
		])  );
}
