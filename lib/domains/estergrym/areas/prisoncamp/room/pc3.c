#include <lib.h>
#include "../prisoncamp.h"
inherit LIB_ROOM;

static void create()
{
	room::create();
	SetShort("northeast corner of the work area");
	SetLong("A large pile of rocks sits in this corner waiting for "
		"the elven prisoners to break them up and haul them away.  "
		"The entrance to the taskmaster's office lies to the south "
		"and the prisoners cell can be seen to the west.  "
		"No activity can be seen immediatly to the south.  ");
	SetExits(  ([
		"south" : P_ROOM + "pc6",
		"west" : P_ROOM + "pc2",
		"southwest" : P_ROOM + "pc5",
		])  );
	SetAmbientLight(30);
	SetClimate("underground");
	SetSmell(  ([
		"default" : "Dirt, dust and persperation fill the air",
		])  );
	SetListen(  ([
		"default" : "Hammers ring as they strike the rock.  ",
		])  );
	SetItems(  ([
		"corner" : "This area is a squared of section carved into "
			"the side of a mountain.  ",
		({ "rocks", "rock", "pile" }) : "Granite, flint the usuaul "
			"make up of mountain rock.",
		({ "taskmaster's office", "entrance", "office" }) :
			"The taskmaster's office is carved into the east "
			"wall of the prison camp.  ",
		({ "prisoner's cell", "cell" }) : "The cell is carved into "
			"the north wall of the prison camp.",
		])  );
	SetInventory(  ([
		P_NPC "melf" : 2,
		])  );
}
