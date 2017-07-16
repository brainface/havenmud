// Title: Durgoroth Town
// File: arena2.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: Sparring room in the Durgoroth arena
//
// Revision History: 
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
    SetTown("Durgoroth");
	SetShort("Durgoroth arena sparring room");
	SetLong("This large semi-circular room holds a vast "
		"arsenal of weaponry. Here the warriors of Durgoroth "
		"can practice the arts of war under the skilled instruction "
		"of the arena's resident weapons masters.");
	SetObviousExits("east");
	SetClimate("indoors");
	SetDomain("FrostMarches");
	SetAmbientLight(35);
	SetItems( ([
		({ "large room","room","arena","sparring room" }) : 
			(: GetLong :),
		({ "arsenal","weaponry" }) : "Racks and stacks of all "
			"types of weapons are everywhere.",
		]) );
	SetExits( ([
		"east" : D_ROOM + "/arena",
		]) );
	SetInventory( ([
		D_NPC + "/culgor" : 1,
		D_NPC + "/shamfast" : 1,
		]) );
	}
