#include <lib.h>
#include "../prisoncamp.h"
inherit LIB_ROOM;

static void create ()
{
	room::create();
	SetShort("center of the work area");
	SetLong("From here one can go in every direction of the compass.  "
		"The camp's gate is looms south of here.  There appears to be a"
		" "
		"cell or holding pen off to the north.  Off to the east lies "
		"the taskmaster's office.  ");
	SetClimate("underground");
	SetAmbientLight(30);
	SetExits(  ([
		"north" : P_ROOM + "pc2",
		"east" : P_ROOM + "pc6",
		"south" : P_ROOM + "pc8",
		"west" : P_ROOM + "pc4",
		"northeast" : P_ROOM + "pc3",
		"northwest" : P_ROOM + "pc1",
		"southeast" : P_ROOM + "pc9",
		"southwest" : P_ROOM + "pc7",
		])  );
	SetItems(  ([
		"gate" : "The gate is not very large and it is well defended.",
		({ "holding pen", "cell", "pen" }) : "A small room is carved "
			"into the north wall of the work area.",
		({ "taskmaster's office", "office" }) : "The entrance to the "
			"taskmaster's office is centered on the east wall.",
		])  );
	SetListen(  ([
		"default" : "Song floats in from the southwest.  ",
		])  );
	SetSmell(  ([
		"default" : "A rank breeze blows in from the southwest.  ",
		])  );
	SetInventory(  ([
		P_NPC "melf" : 3,
		P_NPC "guard" :2,
		])  );
}
