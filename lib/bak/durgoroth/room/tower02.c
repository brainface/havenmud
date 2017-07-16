// Title: Durgoroth Town
// File: tower02.c
// Author: Tim Morris aka Morgoth@Haven
// Date: January 1997
// Abstract: Southeastern guard tower
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("on top of southeastern guard tower");
	SetDayLong("The walls of the fortress can be seen extending "
		"to the north, toward the mountain side, and to the west, "
		"toward the gates. Looking over the parapit the mountain "
		"can be seen falling away down into the valley far below. "
		"A trap-door in the floor leads down in to the "
		"interior of the tower. From a flag pole in the center of "
		"the tower flies the banner of the Crusade.");
	SetNightLong("The walls of the fortress can be seen extending "
		"into the darkness to the north and west. Looking over the "
		"parapit a sea of darkness can be seen where the mountain "
		"drops away down into the valley below. A "
		"trap-door in the floor leads down in to the interior "
		"of the tower. From a flag pole in the center of the "
		"tower flies the banner of the Crusade.");
	SetObviousExits("down");
	SetClimate("sub-arctic");
	SetDomain("FrostMarches");
	SetItems( ([
		({ "wall", "walls","towers", "fortress" }) : "The massive "
			"walls of ancient, weather worn black stone surround the "
			"town. At each corner of the main wall is a large guard "
			"tower. While farther up on the mountain, on a small "
			"plateau, is a crumbling watch tower. ",
		({"guard tower", "tower" }) : "A large circular tower at the "
			"corner of the intersecting western and southern walls of "
			"the fortress. It rises a story above the rampart, with "
			"the banner of the Gorithim rising from its top. A small "
			"wooden trap-door grants access to the interior of the tower.",
		"valley" : "Far far below to the south is the valley "
			"that runs from east to west along the southern spur "
			"of the Frostmarches.",
		({"banner", "banner of the gorithim", "gorithim banner"}) :
			"The banner is a simple device, depicting a a sword and "
			"battle axe crossed over a shield with a snowcapped "
			"mountain painted on it.",
		({"flag pole","flagpole","flag"}) : "A simple wooden pole, "
			"from which flies the banner of the Gorithim.",
		({ "mountain", "mountain side", "mountainside" }) : "The "
			"mountain looms above, the upper pinnicles covered with "
			"deep snow.",
		({"banner of the crusade", "crusade banner", "banner"}) :
			"The banner is an intracite depiction of the angel of "
			"death, bearing a huge two handed sword, decending to "
			"reap the souls of the innocent.",
		]) );
	SetExits( ([
		"down" : D_ROOM+"/wall12",
		]) );
	SetInventory( ([
		D_NPC+"/archer" : 2,
		]) );
	if(query_night())
		SetListen( ([
			"default" : "The eerie call of a lone wolf drifts out "
				"of the darkness.",
		]) );
	}
