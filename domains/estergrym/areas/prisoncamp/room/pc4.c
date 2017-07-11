#include <lib.h>
#include "../prisoncamp.h"
inherit LIB_ROOM;

static void create()
{
	room::create();
	SetShort("work area");
	SetLong("This area has been cleared of rocks.  It appears that "
		"the nosferatu are planning to start a mining operation "
		"at the fissure in the side of the mountain here.  ");
	SetExits(  ([
		"north" : P_ROOM + "pc1",
		"east" : P_ROOM + "pc5",
		"south" : P_ROOM + "pc7",
		"northeast" : P_ROOM + "pc2",
		"southeast" : P_ROOM + "pc8",
		])  );
	SetClimate("underground");
	SetAmbientLight(30);
	SetInventory(  ([
		P_NPC "guard" : 1,
		P_NPC "melf" : 1,
		])  );
	SetListen(  ([
		"default" : "The sounds of singing come from the south.  ",
		])  );
	SetSmell(  ([
		"default" : "A foul stench blows in from the south.  ",
		])  );
	SetItems(  ([
		"fissure" : "This fissure could probably be opened with "
			"very little work.  ",
		"mountain" : "This entire camp is set in the side of a "
			"mountain.  ",
		({ "mining operation", "operation", "mining", "mine" }) :
			"The only signs so far are chalk marks and the "
			"utter lack of rocks and boulders",
		])  );
}
