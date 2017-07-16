#include <lib.h>
#include "../yeah.h"
inherit LIB_ROOM;

static void create() {
	room::create();
	SetClimate("outdoors");
	SetShort("East of Sanctum");
	SetLong("To the west, tall gates are braced open, leading into the beautiful city "
		"of Sanctum along the Via Esteros.  Debris is scattered across the east-west "
		"road.  Cloth flutters on the edge of the Sanctum Wall to the south, "
		"and the Via Esteros continues east.");
	SetItems( ([
			({ "Sanctum gates","gate","gates" }) :
			"The city gates are to the west.",
			({ "Sanctum","city" }) :
			"Sanctum proper is to the west.",
			({ "Via Esteros","road" }) :
			"The Via Esteros degrades into small piles of broken stone "
			"mingling with debris as it stretched to the east.  The "
			"western section of the road, however, is still in good shape.",
			({ "road debris","debris","cloth","kitchenware","waste" }) :
			"Bits and pieces of cloth, human waste, and broken kitchenware litter "
			"the Via Esteros.",
			({ "fluttering cloth","cloth","shelters","shelter" }) : 
			"To the south, pieces of cloth form small shelters.",
			({ "Sanctum wall","wall" }) :
			"The wall stretches high into the air.",
		]) );
	SetItemAdjectives( ([
			"gate" : ({ "sanctum","tall","west" }),
			"city" : ({ "sanctum","beautiful" }),
                        "debris" : ({ "road","human","broken","bits and pieces of" }),
			"shelter" : ({ "small","pieces of","fluttering" }),
			"wall" : ({ "high","sanctum" }),
		]) );
	SetListen( ([
			"default" : "Chattering voices can be heard from the south.",
		]) );
	SetSmell( ([
			"default" : "The stagnant air reeks of sewage.",
			"debris" : "The debris is the obvious source of the rank smell in this section "
					"of Sanctum.",
		]) );
	SetExits( ([
			"east" : A_ROOM + "rd07",
			"south" : A_ROOM + "wall01",
			"west" : WEST_EXIT,
		]) );
	SetInventory( ([

		]) );
}
