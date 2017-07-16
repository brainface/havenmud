// Title: Durgoroth Town
// File: arena.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: Main hall of the Durgoroth arena
//
// Revision History: 
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

int PreExit( object who );

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("main hall of the arena");
	SetLong("This large semi-circular room holds the main "
		"entrance hall of the Durgoroth arena. Here the "
		"visitors and gladiators of the arena mingle and "
		"exchange bets before the fights.");
	SetObviousExits("west, out");
	SetClimate("indoors");
	SetDomain("FrostMarches");
	SetAmbientLight(35);
	SetItems( ([
		({"large room","room","durgoroth arena","arena" }) :
			(: GetLong :),
		]) );
	SetExits( ([
		"west" : D_ROOM + "/arena2",
		"out" : D_ROOM + "/road04",
		]) );
	SetInventory( ([
//              D_OBJ + "/arena_board" : 1,
		D_NPC + "/dergast" : 1,
		D_NPC + "/gladiator" : 1,
		]) );
        SetNewsgroups( ({ "town.durgoroth.arena" }) );
	}

int PreExit( object who ) {
	message( "no", "The Durgoroth Warriors Guild is not currently "
		"open.", who);
	return 0;
	}
