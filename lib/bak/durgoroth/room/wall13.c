// Title: Durgoroth Town
// File: wall13.c
// Author: Tim Morris aka Morgoth@Haven
// Date: January 1998
// Abstract: Eastern wall of the Durgoroth town
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("east wall of Durgoroth");
	SetDayLong("This is the eastern wall of the fortress, it ends "
		"at the "
		"southeastern guard tower here, but continues to the "
		"north toward the steep mountain side. On the other side "
		"of the wall, to the east, the mountain falls away, down "
		"into the valley far below. While to the north the mountain "
		"rises up to incomprenhendible heights. To the south is the "
		"large circular guard tower that stands at the intersection "
		"of the eastern and southern walls of the fortress.");
	SetNightLong("This is the eastern wall of the fortress, it ends "
		"at the "
		"southwestern guard tower here, but continues off into "
		"the darkness to the north. On the other side of the wall, "
		"to the east, lies a sea of blackness where the mountain "
		"drops away into the valley. While to the north the huge "
		"black form of the mountain looms up in the night sky. "
		"Directly to the south is the large circular guard tower "
		"that stands at the intersection of the eastern and "
		"southern walls of the fortress.");
	SetObviousExits("north, tower");
	SetClimate("sub-arctic");
	SetDomain("FrostMarches");
	SetItems( ([
		({ "wall", "walls","towers", "fortress" }) : "The massive "
			"walls of ancient, weather worn black stone surround the "
			"town. At each corner of the main wall is a large guard "
			"tower. While farther up on the mountain, on a small "
			"plateau, is a crumbling watch tower. ",
		({"guard tower", "tower" }) : "A large circular tower at the "
			"corner of the intersecting eastern and southern walls of "
			"the fortress. It rises a story above the rampart, with "
			"the banner of the Crusade rising from its top. A small "
			"wooden door grants access to the interior of the tower.",
		"valley" : "Far far below to the south is the valley "
			"that runs from east to west along the southern spur "
			"of the Frostmarches.",
		({"banner of the crusade", "crusade banner", "banner"}) :
			"The banner is an intracite depiction of the angel of "
			"death, bearing a huge two handed sword, decending to "
			"reap the souls of the innocent.",
		({ "mountain", "mountain side", "mountainside" }) : "The "
			"mountain looms above, the upper pinnicles covered with "
			"deep snow.",
		]) );
	SetExits( ([
		"north" : D_ROOM+"/wall14",
		]) );
	SetEnters( ([
		"tower" : D_ROOM+"/wall12",
		]) );
	}
