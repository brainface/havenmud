#include <lib.h>
#include "../prisoncamp.h"
inherit LIB_ROOM;

static void create()
{
	room::create();
	SetShort("the taskmaster's office");
	SetLong("This room has been cut directly out of the mountain side, "
		"in the same fashion the rest of the camp has been created.  "
		"A rack of torture implements stands in the northwest "
		"corner.  The east wall is lined with shelves.  The "
		"southwest corner is home to a small drafting table.  "
		"A beautifully carved desk sits in the center of the room.");
	SetItems(  ([
		({ "mountain side", "mountain" }) : "The entire prison camp "
			"has been carved into the side of a mountain.  ",
		({ "torture implements", "implements", "rack" }) :
			"All sorts of devices designed to inflict pain "
			"hang here.  ",
		({ "east wall", "shelves", "shelve", "shelf" }) :
			"Hundreds of musty tomes and scrolls line these "
			"shelves.  ",
		({ "scrolls", "scroll", "tomes", "tome" }) :
			"The tomes are mostly about necromancy and the "
			"scrolls record experiments involving the prisoners.",
		({ "southwest corner", "drafting table", "table" }) :
			"The plans for a new bloodgem mine are on the table.",
		({ "plans", "plan" }) : " All that is discernable, is that "
			"the mine will be "
			"opened on the west side of the prison camp.  ",
		"desk" : "A framed letter sits on the desk.  ",
		({ "framed letter", "letter" }) :
			"The letter is starting to yellow with age.  The words "
			"are too faded to discern.",
	])  );
	SetExits (  ([ "west" : P_ROOM + "pc6" ])  );
	SetInventory(  ([ P_NPC "task" :1 ])  );
	SetSmell(  ([
		"default" : "Incense has been burned here recently.",
		])  );
	SetListen(  ([
		"default" : "The rock walls muffle the sounds of the camp.",
		])  );
	SetAmbientLight(30);
	SetClimate("underground");
}
