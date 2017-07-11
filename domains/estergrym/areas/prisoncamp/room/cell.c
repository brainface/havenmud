#include <lib.h>
#include "../prisoncamp.h"
inherit LIB_ROOM;

static void create()
{
	room::create();
	SetShort("the prisoner's quarters");
	SetClimate("underground");
	SetAmbientLight(30);
	SetLong("The cell is a tiny barren room carved into the north wall "
		"of the prison camp.  Three or four people might be able to "
		"lie on the floor comfortably.  Comfort, however, is not "
		"one of the nosferatu's concerns for their prisoners.  "
		"Entire shifts are forced to spend their few hours of rest "
		"cramped into this cell.");
	SetExits(  ([ "south" : P_ROOM + "pc2" ])  );
	SetSmell(  ([
		"default" : "The odor of unbathed elves has seeped into the "
			"very rock.  ",
		])  );
	SetListen(  ([
		"default" : "The rock muffles the sounds of the camp outside.",
		])  );
	SetInventory(  ([
		P_NPC "melf" : 2,
		P_NPC "felf" : 1,
		])  );
}
