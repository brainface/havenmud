// Title: Durgoroth Town
// File: library2.c
// Author: Tim Morris aka Morgoth@Haven
// Date: February 1998
//
// Abstract: Inside the Durgoroth library: Healer's room
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("west end of the Durgoroth Library");
	SetLong("This huge stone edifice contains the massed knowledge "
		"of many generations of the Gorithim and the Nosferatu, as "
		"well as a few treasured tomes from before the God's War. "
		"All around are huge shelves of ancient dusty books. "
		"Narrow aisles lead off into the dim recesses of the library, "
		"With a larger path leading to the east.");
	SetClimate("indoors");
	SetDomain("FrostMarches");
	SetAmbientLight(35);
	SetObviousExits("east");
	SetItems( ([
		({"huge stone edifice","huge edifice","stone edifice",
		"edifice","library"}) : (: GetLong :),
		({"huge shelf","shelf","huge shelves","shelves","book",
		"books","tome","tomes"}) : "Huge shelves of ancient and dusty "
			"books are everywhere. Titles ranges from \"The history "
			"of the lands of Kailie\" to \"Tree frogs and their "
			"uses\".",
		({"narrow aisles","aisles","dim recesses","recesses",
		"narrow aisle","aisle","recess" }) :
			"Narrow aisles between the shelves lead off into the "
			"dim recesses of the library. Where, no doubt, more "
			"books can be found.",
		({"path","paths"}) : "A larger path leads through the "
			"shelves to the east.",
		]) );
	SetExits( ([
		"east" : D_ROOM + "/library",
		]) );
	SetInventory( ([
		D_NPC + "/celia" : 1,
		]) );
	}
