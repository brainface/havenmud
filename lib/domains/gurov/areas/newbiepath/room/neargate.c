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
		"progress to the south.  A couple of tree stumps "
		"indicate spots where the forest was cleared to make "
		"way for the town.  The trail heads off to the "
		"east and west.  Gurov's main gate is visible to the "
		"west.");
	SetItems( ([
		({ "gurov","town" }) : "Gurov is inside the walls.",
		({ "wall","walls","stone" }) : "The perfect grey stone "
			"walls are twenty feet high.",
		({ "underbrush","bush","bushes","forest" }) :
			"Consisting mainly of thorny bushes, the underbrush "
			"makes it difficult, if not impossible, to travel "
			"through the forest.",
		({ "stumps","stump" }) :
			"The small stumps are all that remains of a few "
			"proud trees that made the mistake of growing "
			"where humans wanted to build their town.",
		({ "trail" }) : "The trail extends to the east and west.",
		]) );
	SetItemAdjectives( ([
			"wall" : ({ "high","grey" }),
			"stump" : ({ "tree" }),
			"underbrush" : ({ "thorny" }),
		]) );
	SetExits( ([
			"east" : NP_ROOM + "trail_ew",
                        "west" : "/domains/gurov/towns/gurov/room/gate",
		]) );
	SetInventory( ([
			STD_NPC + "robin" : 2,
			STD_NPC + "butterfly" : 1,
		]) );
}
