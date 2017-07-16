// Title: Durgoroth Town
// File: weapon.c
// Author: Tim Morris aka Morgoth@Haven
// Date: June 1998
//
// Abstract: Jugard's Exceptional Weapons
//
// Revision History: 
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
    SetTown("Durgoroth");
	SetShort("Jugard's Exceptional weapons");
	SetLong("This large workshop is dimly lit by the light of "
		"the forge and by several oil lanterns placed around the "
		"room. In the center of the front portion of the shop "
		"stand racks of various weapons. While in the back is "
		"the workshop with it's forge and assorted work tables "
		"and racks of tools.");
	SetAmbientLight(35);
	SetClimate("indoors");
	SetDomain("FrostMarches");
	SetObviousExits("out");
	SetItems( ([
		({"large workshop","workshop","shop","store"}) : (: GetLong :),
		"forge" : "The small forge at the back of the workshop is "
			"filled with glowing, red-hot coals.",
		({"oil lanters","oil lantern","latern","laterns"}) :
			"Several oil-burning laterns are placed at strategic "
			"locations around the room to help light the dim "
			"workshop.",
		({"racks of weapons","rack","racks","weapons","various weapons"}) :
			"Racks of weapons of all types and sizes are neatly "
			"arranged in the front of the shop.",
		({"work tables","work table","tables","table"}) :
			"Large hardwood tables in the back of the workshop that "
			"are used by Jugard and his assistances while they are "
			"working.",
		({"racks of tools","tools","rack of tools","rack","racks"}) :
			"In the back of the workshop are several racks of tools "
			"related to the weapon smithing trade.",
		]) );
	SetExits( ([
		"out" : D_ROOM + "/market",
		]) );
	SetInventory( ([
		D_NPC + "/jugard" : 1,
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

