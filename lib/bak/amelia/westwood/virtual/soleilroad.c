#include <lib.h>
#include "westwood.h"
inherit LIB_ROOM;

// Defining all non-standard exits
#define SOLEIL_ENT S_ROOM + "tree_c"
#define MONASTERY_ENT WESTWOOD_DIR + "/areas/monastery/room/ent"
#define HIKER_ENT WESTWOOD_DIR + "/areas/hiker/room/trailhead"
#define SOLEILROAD VIRTUAL + "soleilroad/"
#define GOBLINCAMP WESTWOOD_DIR + "/areas/goblin_camp/room/camp_road_01"
#define DUNEDAIN_FOREST WESTWOOD_DIR + "/areas/dunedain_forest/room/forest1"
#define ROOKLAIR WESTWOOD_DIR + "/areas/rooklair/obj/rope1"
#define HOSPITAL_ENT WESTWOOD_DIR + "/areas/hospital/room/start"


static void create(int x, int y) {
   ::create();

// Setting up the basics of all road rooms
   SetDomain("WestWood");
   SetClimate("temperate");
   SetGoMessage("The forest is too dense to proceed in that direction.");
   AddExit("north",SOLEILROAD + x + "," + (y+1));
   AddExit("south",SOLEILROAD + x + "," + (y-1));
   SetSmell( ([
		"default" : "Scents of pine and damp earth fill the air.",
	]) );
   SetListen( ([
		"default" : "The wind shakes the trees, creating a "
			"gentle susurration.",
   	    ]) );

// Just in case something screws up.
   if(x != 0) {
	SetShort("error");
	SetLong("Please report how you managed to enter this room.  It should "
		"not be accessible by players.");
   }


// Setting up the first and last rooms
   if(y == 0) {
	SetShort("next to Soleil");
        SetLong("A gently sloping ramp leads up into the town of Soleil, which "
		"is hidden by the thick branches of tall hemlock trees.  "
		"The Soleil Road continues to the north, weaving around "
		"thick tree trunks.");
	SetItems( ([
			({ "gently sloping ramp","ramp" }) : "The ramp "
				"disappears up into the trees, allowing "
				"access to the town Soleil.",
			({ "soleil" }) : "Soleil is hidden by tree branches.",
			({ "tall hemlock trees","hemlock","hemlocks","tree",
				"trees","branches","branch","pines","pine",
				"needles","needle" }) :
				"Covered in flat pine needles, the tall "
				"hemlock trees surround--and support--the "
				"aerial town of Soleil.",
			({ "soleil road","road" }) : "The road continues to "
				"the north, proceeding deeper into the "
				"WestWood.",
		]) );
	SetItemAdjectives( ([
				"ramp": ({ "gently","sloping" }),
				"tree" : ({ "tall","hemlock","pine","thick","flat" }),
			]) );
	RemoveExit("south");
	AddExit("up",SOLEIL_ENT);
   }
   else if(y == 20) {
	SetShort("near the Eclat Monastery");
	SetLong("The Soleil Road ends here, heading off only to the south.  To the "
                "north, the Eclat Monastery is built up in the trees.  "
                "A trail runs off to the northwest.");
	SetItems( ([
			({ "eclat monastery","monastery" }) : "The monastery, run "
				"by Eclats, is to the north.",
			({ "soleil road","road" }) :
				"The Soleil Road goes south.",
			({ "hiker trail","trail","pleasant trail" }) :
				"The trail heads off to the northwest.",

		]) );
	SetItemAdjectives( ([
				"trees" : ({ "pine","small","thick" }),
			]) );
	RemoveExit("north");
	AddExit("north",MONASTERY_ENT);
        AddExit("northwest",HIKER_ENT);
   }

// Adding the exit to the hospital
   else if(y==2) {
	SetShort("near the Eclat Hospital");
	SetLong("The Soleil Road progresses to the north and south, winding "
		"among the deciduous and coniferous trees.  A path "
		"diverges from the main road here, heading west towards the "
		"famous Eclat Hospital.");
	SetItems( ([
			({ "eclat hospital","hospital" }) : "The Eclat Hospital "
				"is down "
				"the path to the west.",
			({ "pine trees","trees","tree","branches","branch",
				"needles","needle" }) :
				"The trees of the WestWood are primarily pine "
				"trees, with thick branches covered in small "
				"pine needles.",
			({ "deciduous trees","tree","trees","branches","branch",
				"leaves","leaf" }) :
				"A few of the trees in the WestWood are "
				"deciduous.  Broad leaves cover the "
				"branches, swaying in the wind.",
			({ "soleil road","road" }) :
				"The Soleil Road progresses deeper into the "
				"WestWood to the north, while leading back to "
				"Soleil to the south.",
			({ "hard-packed ground","ground","root","roots" }) :
				"Slightly battered roots peak out of the "
				"ground in random spots along the road.",
		]) );
	SetItemAdjectives( ([
			"deciduous trees" : ({ "deciduous","tallest","broad" }),
			"pine trees" : ({ "small","pine","thick" }),
			"hospital" : "famous",
			]) );
	AddExit("west",HOSPITAL_ENT);
   }
/*
// Adding the exit to the dunedain forest
   else if(y==5) {
	SetShort("near a valley");
	SetLong("Tall trees overhang the Soleil Road, while their roots weave along "
		"the hard-packed ground.  While the majority of the trees are "
		"coniferous, a few of the tallest trees are covered in leaves.  "
		"The WestWood breaks to the west, where a valley opens up.");
	SetItems( ([
			({ "pine trees","trees","tree","branches","branch",
				"needles","needle" }) :
				"The trees of the WestWood are primarily pine "
				"trees, with thick branches covered in small "
				"pine needles.",
			({ "deciduous trees","tree","trees","branches","branch",
				"leaves","leaf" }) :
				"A few of the trees in the WestWood are "
				"deciduous.  Broad leaves cover the "
				"branches, swaying in the wind.",
			({ "soleil road","road" }) :
				"The Soleil Road progresses deeper into the "
				"WestWood to the north, while leading back to "
				"Soleil to the south.",
			({ "hard-packed ground","ground","root","roots" }) :
				"Slightly battered roots peak out of the "
				"ground in random spots along the road.",
			({ "valley" }) : "The valley is to the west.",
		]) );
	SetItemsAdjectives( ([
			"deciduous trees" : ({ "deciduous","tallest","broad" }),
			"pine trees" : ({ "small","pine","thick" }),
			]) );
	AddExit("west",DUNEDAIN_FOREST);
   }
*/

// Setting up a "normal" road room.
   else {
	SetShort("on the Soleil Road");
	SetLong("Tall trees overhang the Soleil Road, while their roots weave along "
		"the hard-packed ground.  While the majority of the trees are "
		"coniferous, a few of the tallest trees are covered in leaves.");
	SetItems( ([
			({ "pine trees","trees","tree","branches","branch",
				"needles","needle" }) :
				"The trees of the WestWood are primarily pine "
				"trees, with thick branches covered in small "
				"pine needles.",
			({ "deciduous trees","tree","trees","branches","branch",
				"leaves","leaf" }) :
				"A few of the trees in the WestWood are "
				"deciduous.  Broad leaves cover the "
				"branches, swaying in the wind.",
			({ "soleil road","road" }) :
				"The Soleil Road progresses deeper into the "
				"WestWood to the north, while leading back to "
				"Soleil to the south.",
			({ "hard-packed ground","ground","root","roots" }) :
				"Slightly battered roots peak out of the "
				"ground in random spots along the road.",
		]) );
	SetItemAdjectives( ([
			"deciduous trees" : ({ "deciduous","tallest","broad" }),
			"pine trees" : ({ "small","pine","thick" }),
			]) );
/*
// Setting up an entrance to the goblin camp.
	if(x==15) {
		SetLong(GetLong() + "  The trees are slightly thinner on the west "
			"side of the road.");
		SetSmell("default","A faint, slightly rancid smell comes from the west.");
		AddExit("west",GOBLIN_CAMP);
	}
*/
   }
}
