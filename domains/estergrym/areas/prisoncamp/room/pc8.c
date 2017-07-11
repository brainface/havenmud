#include <lib.h>
#include "../prisoncamp.h"
inherit LIB_ROOM;

static void create() 
{
	room::create();
	SetShort("work area");
	SetLong("Dust rises from the work taking place in all directions.  "
		"Visibility is poor but one can still easily detect the oil "
		" and blood that stain the ground.  The gate lies to the "
		"south.  " );
	SetClimate("underground");
	SetAmbientLight(30);
	SetExits(  ([
		"south" : P_ROOM + "gate",
		"north" : P_ROOM + "pc5",
		"east" : P_ROOM + "pc9",
		"west" : P_ROOM + "pc7",
		"northeast" : P_ROOM + "pc6",
		"northwest" : P_ROOM + "pc4",
		])  );
	SetSmell(  ([
		"default" : "Something nasty blows in from the west",
		"elves" : "They are kinda stinky.",
		])  );
	SetListen(  ([
		"default" : "Someone is singing off to the west.",
		"elves" : "Yes, they even grunt in Eltherian.  ",
 	])  );
	SetItems(  ([
		"dust" : "The dust makes it hard to see.",
		({ "ground", "stain", "blood", "oil" }) :
			"These stains make the very ground "
			"look evil.",
		({ "elves", "elf" }) : "They appear to be over worked.  ",
		({ "gate" }) :  "The gate is well defended.",
		])  );
}
