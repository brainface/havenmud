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
	SetLong("A small bunch of forget-me-nots grow at the corner of "
		"the twenty foot tall walls.  Meeting at a "
		"perfect square angle, the grey stone walls extend "
		"to the north and west.  The thin trail follows "
		"the walls.  Thorny bushes block progress to the south "
		"and east.");
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
			"Growing at the corner of the walls, the forget-"
			"me-nots are small, delicate blue flowers with "
			"a yellow center.",
		({ "trail" }) : "The trail extends to the north and west.",
		]) );
	SetItemAdjectives( ([
			"wall" : ({ "high","grey" }),
			"flowers" : ({ "blue","small","delicate" }),
			"underbrush" : ({ "thorny" }),
		]) );
	SetExits( ([
			"north" : NP_ROOM + "trail_ns1",
			"west" : NP_ROOM + "trail_ew",
		]) );
	SetInventory( ([
			STD_NPC + "raven" : 2,
		]) );
}
