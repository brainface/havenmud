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
	SetLong("Towering above the trail, the grey stone walls "
		"extend to the north and south, blocking all "
		"travel to the west.  The trail follows the "
		"wall, heading north and south.  A turn in "
		"the wall can be seen to the south.  A few "
		"tree stumps spot the trail, and some "
		"forget-me-nots grow at the edge of the wall.  Thorny "
		"brush prevents passage through the forest to the east.");
	SetItems( ([
		({ "gurov","town" }) : "Gurov is inside the walls.",
		({ "wall","walls","stone" }) : "The perfect grey stone "
			"walls are twenty feet high.",
		({ "underbrush","bush","bushes","forest" }) :
			"Consisting mainly of thorny bushes, the underbrush "
			"makes it difficult, if not impossible, to travel "
			"through the forest.",
		({ "flowers","flower","forget-me-not","forget-me-nots",
			"petals","petal" }) :
			"Growing at the edge of the walls, the forget-"
			"me-nots are small, delicate blue flowers with "
			"a yellow center.",
		({ "stumps","stump" }) :
			"The small stumps are all that remains of a few "
			"proud trees that made the mistake of growing "
			"where humans wanted to build their town.",
		({ "trail" }) : "The trail extends to the north and south.",
		]) );
	SetItemAdjectives( ([
			"wall" : ({ "high","grey" }),
			"stump" : ({ "tree" }),
			"flowers" : ({ "blue","small","delicate" }),
			"underbrush" : ({ "thorny" }),
		]) );
	SetExits( ([
			"north" : NP_ROOM + "trail_ns2",
			"south" : NP_ROOM + "corner",
		]) );
	SetInventory( ([
			STD_NPC + "caribou" : 1,
			STD_NPC + "raven" : 1,
		]) );
}
