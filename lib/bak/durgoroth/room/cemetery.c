// Title: Durgoroth Town
// File: cemetary.c
// Author: Tim Morris aka Morgoth@Haven
// Date: January 1997
// Abstract: Durgoroth cemetary
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("Durgoroth cemetery");
	SetDayLong("A good portion of the plateau is set aside for "
		"the cemetery. All around are tombstones of various "
		"sizes, materials, and designs. Some small, some large "
		"some ornate, some plain, some wood, some stone. There "
		"are also several large crypts, their entrances visible "
		"but their bulk buried under ground. To the south the "
		"mountain drops away down to the town below, and then "
		"further down into the valley below.");
	SetNightLong("A good portion of the plateau is set aside for "
		"the cemetery. All around in the darkness are the forms "
		"of tombstones of various sizes, materials, and designs. "
		"Some large, some small, some ornate, some plain, some "
		"wood, some stone. There are also several large crypt "
		"entrances, the interior of their shadowed entrances "
		"a deeper black in the dark night.");
	SetObviousExits("south");
	SetClimate("sub-arctic");
	SetDomain("FrostMarches");
	SetItems( ([
		"plateau" : "A small plateau on the side of the mountain.",
		({"durgoroth cememtery","cemetery"}) : GetLong(),
		({"tombstone","tombstones"}) : "All around are tombstones "
			"of various sizes, materials, and designs. Some small, some "
			"large some ornate, some plain, some wood, some stone.",
		({"large crypt","crypt entrance","crypt","entrance"}) : 
			"There are several large crypts, half buried in the hard "
			"ground. Their interiors can not be seen past the shadowed "
			"entrances.",
		({"mountain", "mountain side", "mountainside" }) : "The "
			"mountain looms above, the upper pinnicles covered with "
			"deep snow.",
		({ "fortress", "durgoroth", "town", "fortress town",
		"durgoroth town", "durgoroth fortress" }) : "The massive, "
			"slightly crumbling stone walls and towers of the "
			"fortress spread out below. Its huge rectangular form "
			"sticking out like a sore thumb in the wilderness to "
			"all sides.",
		"valley" : "Far far below to the south is the valley "
			"that runs from east to west along the southern spur "
			"of the Frostmarches.",
		]) );
	SetExits( ([
		"south" : D_ROOM+"/wall17",
		]) );
	SetEnters( ([
//		"large crypt" : D_ROOM + "/necro1",
		]) );
	SetInventory( ([
		D_NPC+"/glaurung" : 1,
		]) );
	SetSmell( ([
		"default" : "There is a faint musty odor, and a smell of "
			"freshly dug earth.",
		]) );
	if(query_night())
		SetListen( ([
			"default" : "The eerie call of a lone wolf drifts out "
				"of the darkness.",
		]) );
	else
		SetListen( ([
			"default" : "The call of a raven echoes in the quiet "
				"mountain air.",
		]) );
}
