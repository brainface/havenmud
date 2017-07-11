#include <lib.h>
#include "../prisoncamp.h"
inherit LIB_ROOM;

static void create()
{
	room::create();
	SetShort("southwest corner of the work area");
	SetLong("This corner of the camp serves a dual purpose.  The first "
		"purpose is quite obvious from the foul stench that hangs "
		"in the air.  The prisoners leave their waste here.  The "
		"second purpose is that the taskmaster takes amusement in "
		"randomly selecting prisoners to work amongst the waste.  "
		"Since the elves are not allowed to bathe, the other "
		"prisoners shun their company till the stench wears off.");
	SetClimate("underground");
	SetAmbientLight(30);
	SetSmell(  ([ "default" : "The stench of excrement is overpowering."  
	])  );
	SetExits(  ([
		"north" : P_ROOM + "pc4",
		"east" : P_ROOM + "pc8",
		"northeast" : P_ROOM + "pc5",
		])  );
	SetInventory(  ([P_NPC "felf" : 1 ])  );
	SetListen(  ([
		"default" : "Hammers and stone ring to the northeast.",
		])  );
	SetItems(  ([
		({ "excrement", "waste" }) : "Don't look at that.  That's "
			"nasty.",
		"corner" : "This part of the mountain has been excavated to "
			"a squared off corner.  ",
		]) );
}
