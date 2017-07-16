// Title: Durgoroth Town
// File: wall11.c
// Author: Tim Morris aka Morgoth@Haven
// Date: January 1998
// Abstract: Near southeastern guard tower of the Durgoroth town
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("southern wall of Durgoroth");
	SetDayLong("This is the southern wall of the fortress, it ends "
		"at the "
		"southeastern guard tower here, but continues to the "
		"west toward the gates of the fortress. On the other side "
		"of the wall, to the south, the mountain falls away, down "
		"into the valley far below. To the east is the large "
		"circular guard tower that stands at the intersection of "
		"the eastern and southern walls of the fortress. To the "
		"northwest, the back of the Durgoroth bank can be seen.");
	SetNightLong("This is the southern wall of the fortress, it "
		"ends at the "
		"southwestern guard tower here, but continues off into "
		"the darkness to the west. On the other side of the wall, "
		"to the south, lies a sea of blackness where the mountain "
		"drops away into the valley. Directly to the east is the "
		"large circular guard tower that stands at the intersection "
		"of the eastern and southern walls of the fortress. And to "
		"the northwest the back of the Durgoroth bank can be seen. ");
	SetObviousExits("west, tower");
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
			"that runs from east to west along the crystal "
			"reaches, clear from Haven town to the western sea.",
		({"banner of the crusade", "crusade banner", "banner"}) :
			"The banner is an intracite depiction of the angel of "
			"death, bearing a huge two handed sword, decending to "
			"reap the souls of the innocent.",
		({ "mountain", "mountain side", "mountainside" }) : "The "
			"mountain looms above, the upper pinnicles covered with "
			"deep snow.",
		({"durgoroth bank", "bank" }) : "The large imposing stone "
			"building houses the Durgoroth bank, where the "
			"citizens of the town can deposit and exchange their "
			"coins.",
		]) );
	SetExits( ([
		"west" : D_ROOM+"/wall10",
		]) );
	SetEnters( ([
		"tower" : D_ROOM+"/wall12",
		]) );
	}
