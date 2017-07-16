// Title: Durgoroth Town
// File: library.c
// Author: Tim Morris aka Morgoth@Haven
// Date: January 1997
// Abstract: Durgoroth library
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("Durgoroth library");
	SetLong("This huge stone edifice contains the massed knowledge "
		"of many generations of the Gorithim and the Nosferatu, as "
		"well as a few treasured tomes from before the God's War. "
		"All around are huge shelves of ancient dusty books. "
		"Narrow aisles lead off into the dim recesses of the library, "
		"With larger paths leading to the north and west.");
	SetClimate("indoors");
	SetDomain("FrostMarches");
	SetAmbientLight(35);
	SetObviousExits("north, west, out");
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
		({"path","paths"}) : "Two larger paths lead through the "
			"shelves to the north and the west.",
		]) );
        SetNewsgroups( ({ "magic.ideas" }) );
	SetExits( ([
		"north" : D_ROOM+"/library3",
		"west" : D_ROOM+"/library2",
		"out" : D_ROOM+"/road10",
		]) );
	SetInventory( ([
		D_NPC+"/uruial" : 1,
		D_NPC+"/mortigern" : 1,
        D_NPC+"/sandis" : 1,
		]) );
	}
