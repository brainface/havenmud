// Title: Durgoroth Town
// File: inn.c
// Author: Timothy Morris aka Morgoth@Haven
// Date: June 1998
//
// Abstract: The Black Sun Inn in Durgoroth
//
// Revision History: 
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
    SetTown("Durgoroth");
	SetShort("common room of the Black Sun Inn");
	SetDayLong("This large room bustles with activity. Patrons "
		"come and go. Some come for the food, others for lodging. "
		"Many travelers for far lands can be found here. Around the "
		"room are large round tables with various people sitting at "
		"them, eating or talking. At the back of the room is a "
		"narrow staircase going up to the rooms above.");
	SetNightLong("This large room sits fairly empty now, with just "
		"a few people sitting here and there eating a late supper "
		"before going home to bed or to the rooms above. The room "
		"is lit dimly by lanterns hanging around the walls. All "
		"the room are large round tables, mostly empty as the night "
		"wears on.");
	SetObviousExits("up, out");
	SetClimate("indoors");
	SetDomain("FrostMarches");
	SetAmbientLight(40);
	SetItems( ([
		({"room","large room","inn","black sun inn"}) : (: GetLong :),
		({"patrons","patron","travelers"}) : "Patrons of all "
			"races and sizes come and go in and out of the inn "
			"going about their business.",
		({"large round tables","large tables","round tables",
			"large round table","large table","round table",
			"tables","table"}) : "Large, round, tables made "
			"of thick, hard wood. Many of the tables are stained "
			"by years of constant use.",
		({"narrow staircase","narrow stair","narrow stairs",
			"staircase","stair","stairs"}) : "A narrow staircase "
			"at the back of the room that leads up to the "
			"rooms above.",
		({"lanters","lantern"}) : "Large brass oil-burning lanterns "
			"hang around the room to light it at night.",

		]) );
	SetExits( ([
		"out" : D_ROOM + "/road03",
		"up" : D_ROOM + "/inn2",
		]) );
	if(!query_night())
		SetListen( ([
			"default" : "The room bustles with activity and loud "
				"talking.",
			]) );
	SetSmell( ([
		"default" : "The smell of food cooking drifts out from the "
			"kitchen.",
		]) );
	SetInventory( ([
		D_NPC + "/innkeeper" : 1,
		]) );
	}
