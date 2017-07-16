// Title: Durgoroth Town
// File: market.c
// Author: Tim Morris aka Morgoth@Haven
// Date: February 1998
//
// Abstract: Center of the indoor marketplace of Durgoroth
//
// Revision History: 
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
    SetTown("Durgoroth");
	SetShort("center of the Durgoroth Marketplace");
	SetLong("This large wooden building contains the stores and "
		"workshops of the town's craftsmen and shop keepers. "
		"Prominent among them are Mavox's General Store, "
		"Jugard's Exceptional Weapons, and Durgoroth's Finest armours.");
	SetClimate("indoors");
	SetDomain("FrostMarches");
	SetAmbientLight(35);
	SetObviousExits("north, south, east, west, northwest, southeast");
	SetItems( ([
		({"large wooden building","large building","wooden building",
		"building","market","marketplace" }) : (: GetLong :),
		({"mavox's general store","general store","store" })
			: "Mavox's general store is a small store front "
			"sporting a ornate sign declaring it to be a general "
			"store. Many types of items can be bought and sold here "
			"and Mavox is reputedly a fair man. It is to the north.",
		({"jugard's weaponsmiths","weaponsmiths","weaponsmith",
		"weapon smiths","weaponry","smiths","smith","store",
		"workshop","exceptional weapons"}) : "Jugard's weaponsmiths is a place where "
			"you can go to purchase, sell, and repair weapons of "
			"all types. Jugard's weapons have a reputation of "
			"being excellent quality. It is to the west",
		({"durgoroth's finest armours","armourers","armourer",
		"armoury","armour","store","workshop","hargard's finest",
		"durgoroth armours","durgoroth's finest"}) :
			"One may buy and sell various armours at Hargard's shop. "
			"As well as repair the marks of battle upon their "
			"armour. It is to the northwest.",
		({ "shop","shops" }) : "Do you mean the general store, the "
			"weaponsmiths, or the armourers?",
		]) );
	SetExits( ([
		"east" : D_ROOM + "/road11",
		"southeast" : D_ROOM + "/road07",
		"south" : D_ROOM + "/road06",
		"north" : D_ROOM + "/general",
		"west" : D_ROOM + "/weapon",
		"northwest" : D_ROOM + "/armour",
		]) );
	SetListen( ([
		"default" : "The loud sounds of hammers striking metal "
			"reverberate throughout the building.",
		]) );
        SetNewsgroups( ({ "town.durgoroth" }) );
	SetInventory( ([
		D_NPC + "/guard" : 1,
                D_OBJ + "/poster" : 1,
		]) );
	}
