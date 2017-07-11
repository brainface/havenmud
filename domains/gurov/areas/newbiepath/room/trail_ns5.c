#include <std.h>
#include <lib.h>
#include <domains.h>
#include "../np.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("a path outside Gurov's walls");
	SetSmell( ([
		"default" : "Aromas of the ocean dominate the area.",
		]) );
	SetListen( ([
		"default" : "The crashing of waves mixes with muted "
			"city noises from inside Gurov.",
		"sea" : "The North Sea rhythmically breaks its waves "
			"against the cliff.", 
		]) );
	SetLong(
	  "The towering grey walls end with the trail at a sheer "
		"cliff that blocks progress to the north.  The North "
		"Sea methodically surges and crashes against the base "
		"of the cliff, slowly degrading the rock into "
		"soft sand.  The trail heads off to the south, following "
		"the walls.  The forest blocks progress to the east, "
		"growing up to the edge of the cliff. A large bush grows "
		"next to the wall."
		);
	SetItems( ([
		({ "gurov","town" }) : "Gurov is inside the walls.",
		({ "wall","walls","stone" }) : "The perfect grey stone "
			"walls are twenty feet high.",
		({ "underbrush", "bushes", "forest" }) :
			"Consisting mainly of thorny bushes, the underbrush "
			"makes it difficult, if not impossible, to travel "
			"through the forest. One bush grows next to the wall.",
		({ "cliff","rock" }) :
			"It would be suicidal to attempt to climb down the "
			"vertical cliff.  Its smooth surface offers no "
			"hand or foot-holds.  Even the promiscuous forest "
			"has not found room to grow on the cliff.",
		({ "North Sea","sea" }) :
			"The North Sea surges against the cliff below.",
		({ "trail" }) : "The trail extends to the south.",
		"bush" : "Behind this bush is an opening leading <down>.",
		]) );
	SetItemAdjectives( ([
			"wall" : ({ "high","grey","towering" }),
			"underbrush" : ({ "thorny" }),
			"cliff" : ({ "sheer","vertical" }),
			"sea" : ({ "north" }),
		]) );
	SetExits( ([
			"south" : NP_ROOM + "trail_ns4",
			"down"  : GUROV_TOWNS "gurov/room/guild2",
		]) );
  SetObviousExits("south");
	SetInventory( ([
			STD_NPC + "raven" : 2,
			STD_NPC + "jay_blue" : 1,
		]) );
}
