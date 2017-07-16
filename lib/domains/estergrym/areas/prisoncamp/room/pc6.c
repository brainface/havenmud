#include <lib.h>
#include "../prisoncamp.h"
inherit LIB_ROOM;

static void create()
{
	room::create();
	SetShort("work area");
	SetLong("There are no prisoners or guards here.  One might surmise "
		"that this is due to the existance of the taskmaster's "
		"office just east of here.  Work continues in most other "
		"directions.  ");
	SetClimate("underground");
	SetAmbientLight(30);
	SetExits(  ([
		"north" : P_ROOM + "pc3",
		"east" : P_ROOM + "office",
		"south" : P_ROOM + "pc9",
		"west" : P_ROOM + "pc5",
		"northwest" : P_ROOM + "pc2",
		"southwest" : P_ROOM + "pc8",
		])  );
	SetItems(  ([
		({ "taskmaster's office", "office" }) :
			"An open arch or door has been made into the east "
			"wall.  The office is not well lit so one can not "
			"make out any details from outside.  ",
		])  );
	SetListen(  ([
		"default" : "Pacing and muttering can be heard coming from "
			"inside the office.  ",
		])  );
	SetSmell(  ([
		"default" : "Incense faintly wafts from the office.  ",
		])  );
}
