#include <lib.h>
#include "../soleil.h"
inherit LIB_ROOM;

static void create() {
	::create();
	SetDomain("WestWood");
	SetShort("the Soleil Road");
	SetLong("The tall trees of the WestWood crowd the edges of the "
		"Soleil Road, their boughs "
		"forming thick arches above the hard-packed dirt.  Footprints "
		"mark the edges of the road, where the ground is still loose "
		"enough to form mud.  The road travels north and south.");
	SetItems( ([
			({ "soleil road","road" }) : (: GetLong() :),
			({ "westwood trees","boughs","bough","tree","westwood",
				"pines","limb","limbs","pine","branches",
				"branch", }) :
				"Short, pointed pines cover the tree limbs "
				"like quills on a frightened porcupine, sticking "
				"out of the branches in all directions.  "
				"A few of the tallest trees bear leaves.",
			({ "tallest trees","tree","trees","leaf","leaves" }) :
				"Standing out of the forest like great monoliths, "
				"the tallest trees of the WestWood are deciduous.  "
				"The tops are high enough to wave in air currents "
				"that are not felt down on the ground.",
			({ "hard-packed dirt","dirt","ground" }) :
				"The Soleil Road is not paved, but is merely "
				"dirt that has been stomped into a hard, "
				"easily-navigatable surface.  The edges are muddy.",
			({ "footprints","footprint","mud" }) :
				"Some of the footprints can be identified as "
				"muezzin, but the larger halfling feet and "
				"the smaller gelfling feet are also visible in "
				"the mud on the edge of the road.",
		]));
	SetItemAdjectives( ([
				"pine" : ({ "tall","westwood","tree","short","pointed","pine" }),
				"leaf" : ({ "tallest","decidious" }),
			]) );
	SetListen( ([
			"default" : "A gentle susurrous of shaking trees fills in "
				"the WestWood.",
			"pine" : "The pine needles make little sound individually, but "
				"as thousands rub against thousands, they whisper "
				"with persistent, soft noise.",
			"leaf" : "The leaves shuffling against each other forms a "
				"crackling noise, like crumpling parchment.",
		]) );
	SetSmell( ([
			"default" : "Scents of fresh dirt and tree sap fill the air.",
			"dirt" : "It smells earthy.",
			({ "pine","leaf" }) : "The trees have a distinct sap smell, "
				"especially the pine trees.",
		]) );
	SetInventory( ([
			S_NPC + "citizenf" : 3,
			S_NPC + "citizenm" : 2,
                  S_OBJ + "wantedposter" : 1,
			]) );
	SetExits( ([
			"north" : S_ROOM + "gate",
			"south" : S_ROOM + "soleilroad01",
		]) );
}
