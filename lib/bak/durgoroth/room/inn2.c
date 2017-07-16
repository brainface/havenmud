// Title: Durgoroth Town
// File: inn2.c
// Author: Timothy Morris aka Morgoth@Haven
// Date: June 1998
//
// Abstract:	The common sleeping room of the Black Sun Inn in
//				Durgoroth
//
// Revision History: 
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
    SetTown("Durgoroth");
	SetShort("common sleeping room");
	SetLong("This dim, windowless room contains a dozen or "
		"so beds lined up along the walls of the room. Lanters "
		"hung from the rafters light the room. At the end of the "
		"room is a narrow staircase going down into the common "
		"room of the Inn below.");
	SetObviousExits("down");
	SetClimate("indoors");
	SetDomain("FrostMarches");
	SetAmbientLight(30);
	SetItems( ([
		({"dim room","windowless room","room"}) : (: GetLong :),
		({"beds","bed"}) : "The sagging mattresses are used by "
			"patrons who aren't staying long or don't want to "
			"pay for a private room.",
		({"lantern","lanterns"}) : "Brass oil-burning lanters "
			"are hung from the rafters to try and heat the room.",
		({"rafters","rafter"}) : "Wooden rafters that support the "
			"roof of the inn.",
		({"narrow staircase","narrow stairs","narrow stair",
			"staircase","stairs","stair"}) : "A narrow staircase "
			"leads down into the common room of the Dark Sun Inn.",
		]) );
	SetExits( ([
		"down" : D_ROOM + "/inn",
		]) );
	SetInventory( ([
		D_NPC + "/zafir" : 1,
		]) );
	}
