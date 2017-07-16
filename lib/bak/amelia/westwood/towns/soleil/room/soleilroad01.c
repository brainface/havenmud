#include <lib.h>
#include "../soleil.h"
inherit LIB_ROOM;

#define START  "/domains/southern_coast/virtual/havenroad/-20,0"
int PreExit();

static void create() {
	::create();
	SetDomain("WestWood");
	SetShort("the Soleil Road");
	SetLong("The tall trees of the WestWood crowd the edges of the "
		"Soleil Road, their boughs "
		"forming thick arches above the hard-packed dirt.  The "
		"trees thin out to the south, where the Soleil Road intersects "
		"with the Imperial Road.  To the north, the trees are more "
		"tightly packed around the edges of the road.");
	SetItems( ([
			({ "soleil road","road" }) : (: GetLong() :),
			({ "imperial road","road" }) : "The Imperial Road is "
				"to the south, where the trees are thinner.",
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
			({ "hard-packed dirt","dirt" }) :
				"The Soleil Road is not paved, but is merely "
				"dirt that has been stomped into a hard, "
				"easily-navigatable surface.",
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
			S_NPC + "citizenf" : 1,
			S_NPC + "citizenm" : 1,
			]) );
	SetExits( ([
			"north" : S_ROOM + "soleilroad02",
		]) );
	AddExit("south",START,(:PreExit:));
}

int PreExit() {
  if(this_player()->GetProperty("soleilnoleave")) return 0;
  return 1;
}
