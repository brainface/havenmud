// Title: Durgoroth Town
// File: road03.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1997
// Abstract: The road just inside the gates to the town of Durgoroth
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("Durgoroth");
	SetShort("inside the gates of Durgoroth");
	SetDayLong("Directly to the south are the gates of the town. "
		"The main road of Durgoroth leads off to the north, to "
		"the center of the town. Overhead is the main wall of the "
		"fortress, with a large stair near the gate leading up to "
		"its top. To the west is the Black Sun inn. The town is "
		"amazingly clean and well ordered considering its "
		"inhabitants.");
	SetNightLong("Directly to the south are the gates to the town. "
		"The main road of Durgoroth leads off into the shadows "
		"to the north, to the center of the town. Overhead is the "
		"main wall of the fortress, looming like a great black "
		"shadow against the lesser darkness of the night sky. A "
		"large stair near the gate leads to the top of the wall. "
		"To the west is the Black Sun inn, its windows glowing "
		"welcomingly. ");
	SetObviousExits("north, south, up");
	SetClimate("sub-arctic");
	SetDomain("FrostMarches");
	SetItems( ([
		({"gate","gates","small door","door","planks","black wood",
			"wood"}) :
			"The massive wooden gates are "
			"formed of huge planks of a hard, black wood. "
			"In one of the gates is a smaller door, about the "
			"size for one person to fit through bent over.",
		({ "main road", "road" }) : "The main road of Durgoroth "
			"leads from the gates north to the edge of the steep "
			"mountain side.",
		({ "wall", "walls", "tower", "towers", "fortress" }) : 
			"The massive walls of ancient, weather worn black "
			"stone surround the town. At each corner of the main "
			"wall is a large guard tower. While farther up on the "
			"mountain, on a small plateau, is a crumbling watch "
			"tower. ",
		"watch tower" : "It is too far away to see much of the details.",
		({"mountain", "mountain side"}) : "The mountain looms above, "
			"the upper pinnicles covered with deep snow.",
		({"large stair","stair"}) : "A large, worn, stone stair "
			"leads from near the gate, up the wall to its top.",
		({ "black sun inn", "black sun", "inn", "building" }) :
			"The Black Sun inn "
			"is a large, two story, wood and stone block building. "
			"Smoke pours from the chimney at the back of the building, "
			"where the kitchen must be. Travellers are always welcome, "
			"if they have the coins to pay for their stay. ",
		({"chimney","smoke"}) : "Smoke pours from the chimney of "
			"the Black Sun Inn.",
		]) );
	SetExits( ([
		"north" : D_ROOM+"/road07",
		"south" : D_ROOM+"/road02",
		"up" : D_ROOM+"/wall08",
		]) );
	SetEnters( ([
		"inn" : D_ROOM+"/inn",
		]) );
	SetInventory( ([
		D_NPC+"/guard1" : 1,
		D_NPC+"/guard2" : 1,
		]) );
	}
