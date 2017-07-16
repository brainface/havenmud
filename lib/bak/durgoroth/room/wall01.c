// Title: Durgoroth Town
// File: wall01.c
// Author: Tim Morris aka Morgoth@Haven
// Date: January 1998
// Abstract: Northwestern end of the Durgoroth town wall
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("northwestern end of the wall");
	SetDayLong("This wall of the fortress ends against the steep mountain "
		"side here, but continues around the town to the south. To the "
		"north the mountain rises up steeply to incomprehendable heights. "
		"On the other side of the wall to the west, the mountain drops away, "
		"down into the valley. To the east lies the Durgoroth arena, "
		"the interior can not quite be seen over the lip of the structure.");
	SetNightLong("This wall of the fortress ends agains the steep mountain "
		"side here, but continues into the darkness to the south. To the "
		"north the mountain rises away into the dark night sky. On the other "
		"side of the wall lies a sea of blackness where the mountain drops "
		"away down to the valley. To the east lies the now quiet black form "
		"of the Durgoroth arena.");
	SetObviousExits("south");
	SetClimate("sub-arctic");
	SetDomain("FrostMarches");
	SetItems( ([
		({ "wall", "walls", "fortress" }) : 
			"The massive walls of ancient, weather worn black "
			"stone surround the town. At each corner of the main "
			"wall is a large guard tower. While farther up on the "
			"mountain, on a small plateau, is a crumbling watch "
			"tower. ",
		({ "mountain", "mountain side", "mountainside" }) : "The "
			"mountain looms above, the upper pinnicles covered with "
			"deep snow.",
		"valley" : "Far far below to the south is the valley "
			"that runs from east to west along the southern spur "
			"of the Frostmarches.",
		]) );
		if( query_night())
		AddItem(({"durgoroth arena", "arena"}), "The massive circular "
			"structure blocks out an entire quadrent of the stars, "
			"dwarfing the structures next door and across the street. ");
		else
		AddItem(({"durgoroth arena", "arena"}), "It's massive circular "
			"structure dwarfing the tavern across the way. The loud "
			"sounds of \"Boo's\" and cheers come from within, with an "
			"occasional loud clang of a sword striking a shield with "
			"great force.");
	SetExits( ([
		"south" : D_ROOM+"/wall02",
		]) );
	if(!query_night())
		SetListen( ([
			"default" : "The loud sounds of \"Boo's\" and cheers come from "
				"the arena, with an occasional loud clang of a weapon "
				"striking a shield.",
		]) );
	}
