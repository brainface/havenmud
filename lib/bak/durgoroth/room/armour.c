// Title: Durgoroth Town
// File: armour.c
// Author: Tim Morris aka Morgoth@Haven
// Date: June 1998
//
// Abstract: Durgoroth's Finest Armours, owned by Hargard
//
// Revision History: 
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetShort("Durgoroth's Finest Armours");
	SetLong("This large workshop is dimly lit by the light of "
		"the forge. All around are pieces of armour in "
		"various states of completion and repair. Along the "
		"walls are racks of other armours for sale. At one "
		"end of the room is the large forge and bellows, near "
		"which stand racks of tools related to the trade of "
		"armourer.");
	SetAmbientLight(30);
	SetClimate("indoors");
	SetDomain("FrostMarches");
	SetObviousExits("out");
	SetItems( ([
		({"workshop","durgoroth's finest armours","durgoroth's finest",
			"durgoroth's armours","shop","store","room"}) :
			(: GetLong :),
		({"forge","large forge"}) : "A large stone forge filled with "
			"glowing red hot coals. It looks incredibly hot, and it "
			"has to be, in order to melt metal.",
		({"peices of armour","armour","racks","racks of armour","rack",
			"rack of armour"}) : "All about the floor of "
			"the shop and on ranks on the walls are all types "
			"of armours, some in construction, some in for repair "
			"some up for sale.",
		({"wall","walls"}) : "All around the walls are racks of "
			"armour.",
		"bellows" : "The huge bellows are used to blow air into the "
			"forge to help heat it to the tremendous temperature "
			"required.",
		({"racks of tools","rack of tools","tool racks","tool rack",
			"racks","rack","tools","tool"}) : "Racks of tools "
			"near the forge related to the armour making trade.",
		]) );
	SetExits( ([
		"out" : D_ROOM + "/market",
		]) );
	SetInventory( ([
		D_NPC + "/hargard" : 1,
		]) );
  	SetProperties( ([
       	"metal repair" : 1,
	      "natural repair" : 1,
        	"wood repair" : 1,
        	"leather repair" : 1,
        	"textile repair" : 1,
        	"mithral repair" : 1,
      	]) );
	}
