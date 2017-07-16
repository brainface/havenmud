#include <std.h>
#include <lib.h>
#include "../np.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetShort("a path outside Gurov's walls");
	SetSmell( ([
		"default" : "Aromas of the forest dominate the area.",
		]) );
	SetListen( ([
		"default" : "The chirping of birds mixes with muted "
			"city noises from inside Gurov.",
		]) );
	SetLong("The thin trail leads through the forest on the outside "
		"of Gurov's high stone walls.  The walls extend to the "
		"east and west, blocking travel to the north.  Thick "
		"underbrush, consisting mainly of thorny bushes, blocks "
		"progress to the south.  A few fallen branches "
		"litter the trail.  A turn in the wall can be seen to "
		"the east.  The trail extends to the east and west.");
	SetItems( ([
		({ "gurov","town" }) : "Gurov is inside the walls.",
		({ "wall","walls","stone" }) : "The perfect grey stone "
			"walls are twenty feet high.",
		({ "underbrush","bush","bushes","forest" }) :
			"Consisting mainly of thorny bushes, the underbrush "
			"makes it difficult, if not impossible, to travel "
			"through the forest.",
		({ "branch","branches","needles","needle" }) :
			"The branches are covered in small pine needles, and "
			"are not very large.",
		({ "trail" }) : "The trail extends to the east and west.",
		]) );
	SetItemAdjectives( ([
			"wall" : ({ "high","grey" }),
			"branch" : ({ "fallen","small","pine" }),
			"underbrush" : ({ "thorny" }),
		]) );
	SetExits( ([
			"east" : NP_ROOM + "corner",
			"west" : NP_ROOM + "neargate",
		]) );
	SetInventory( ([
			STD_NPC + "jay_blue" : 2,
			STD_NPC + "squirrel" : 1,
		]) );
}
