#include <lib.h>
#include "../prisoncamp.h"
inherit LIB_ROOM;

static void create()
{
	room::create();
	SetShort("northwest corner of work area");
	SetLong("This area is slightly organized.  A few wheelbarrows are "
		"lined along the west wall.  A fairly empty toolrack is "
		"attached to the north wall.  The entrance to the prisoner's "
		"quarters is to the east.");
	SetClimate("underground");
	SetExits(  ([
		"east" : P_ROOM + "pc2",
		"south" : P_ROOM + "pc4",
		"southeast" : P_ROOM + "pc5",
		])  );
	SetItems(  ([
		({ "wheelbarrows", "wheelbarrow" }) : "These are used to haul "
			"rock.  All of them are empty.  ",
		"wall" : "A cave wall.",
		({ "toolrack", "tools," "tool", "rack" }) : "The ones that are "
			"left in the rack are worthless.  Apparently the elves "
			"grab the best tools at the beging of each work shift.",

		({ "prisoner's quarters", "quarters" }) : "It can not quite be "
			"made out from here.  ",
		])  );
	SetAmbientLight(30);
	SetSmell(  ([
		"default" : "Oil pervades the air.  ",
		])  );
	SetListen(  ([
		"default" : "The sounds of work come from the southeast.  ",
		])  );
	SetInventory(  ([
		P_NPC "guard" : 1,
		])  );
}
