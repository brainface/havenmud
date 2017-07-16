// Title: Durgoroth Town
// File: road02.c
// Author: Tim Morris aka Morgoth@Haven
// Date: December 1997
// Abstract: The road just outside the gates to the town of Durgoroth
//
// Revision History:
//

#include <lib.h>
inherit LIB_ROOM;
#include "../durgoroth.h"

static void create() {
	room::create();
	SetTown("durgoroth");
	SetShort("Outside the gates of Durgoroth");
	SetLong("This road continues down into the valley to the south. "
		"Directly to the north stands the gates to the fortress town "
		"of Durgoroth. Up close, the fortress begins to look "
		"distinctly sinister. The surface of the large, heavy, wooden "
		"gates is covered with large metal spikes. And from the "
		"ramparts above protrude a number of pikes with heads and "
		"skulls in various states of decay impaled on them. The "
		"massive stone walls and towers of the fortress loom over "
		"you, blocking out all of the mountain behind exept for the "
		"very tip.");
	SetObviousExits("north, south");
	SetClimate("sub-arctic");
	SetDomain("FrostMarches");
	SetItems( ([
		({"mountain road","road","path"}) :
			"The mountain road continues down into the valley below.",
		"valley" : "Far far below to the south is the valley "
			"that runs from east to west along the southern spur "
			"of the Frostmarches.",
		({ "fortress", "durgoroth", "town", "fortress town",
		"durgoroth town", "durgoroth fortress" }) : "Up close, "
			"the fortress begins to look distinctly "
			"sinister. From the ramparts above protrude a number of "
			"pikes with heads and skulls in various states of decay "
			"impaled on them. The massive, slightly crumbling, stone "
			"walls and towers of the fortress loom over you, blocking "
			"out all of the mountain behind exept for the very tip.",
		({ "rampart", "ramparts" }) : "The rampart runs along the top "
			"of the wall between the towers and the mountain-side. The "
			"eastern rampart joins a stair leading up to the watch tower "
			"higher up on the mountain.",
		({ "pike", "pikes", "head", "heads", "skull", "skulls" }) : "A "
			"rather large number of heads and skulls of various races "
			"are impaled on pikes sticking from the ramparts above the "
			"gates to the town. Slain enemies of the residents of the "
			"town no doubt.",
		({ "stone walls","stone wall","wall","walls","tower",
		"towers" }) : "The massive walls "
			"of ancient, weather worn black stone surround the town. At "
			"each corner of the main wall is a large guard tower. While "
			"farther up on the mountain, on a small plateau, is a "
			"crumbling watch tower. ",
		"watch tower" : "It is too far away to see much of the details.",
		({ "mountain","pinnacle","mountain tip"}) : "The mountain "
			"looms above, the upper pinnacles covered with deep snow.",
		({"guard tower", "guard towers"}) : "Two guard "
			"towers, one at each end of the main wall of "
			"Durgoroth.",
		({"snow","deep snow"}) : "Deep white snow covers the "
			"pinnacle of the mountain.",
		({"small plateau","plateau"}) : "A small plataue far "
			"up on the mountain above the town.",
		({ "heavy wooden gates", "heavy gates", "wooden gates",
			"gates", "gate", "heavy gate", "wooden gate" }) :
			"The massive wooden gates are formed of huge planks of a "
			"hard, black wood. Protruding from the surface of the door "
			"about every 10 inches is a huge, 6\" long, iron spike. In "
			"one of the gates is a smaller door, about the size for one "
			"person to fit through bent over.",
		({ "large spikes","metal spikes","spikes", "large spike",
			"metal spike","spike","iron spike","iron spikes" }) :
			"The surface of the massive wooden gates is covered "
			"with many huge, 6\" long, iron spikes.",
		({ "small door","door" }) : "In one of the large main gates "
			"is a small door, about the right height for a person to "
			"fit through if they bent over.",
		]) );
	SetExits( ([
		"north" : D_ROOM+"/road03",
		"south" : D_ROOM+"/road01",
		]) );
//	SetDoor("north", D_OBJ+"/gates");
	SetInventory( ([
		D_NPC+"/gate_guard" : 1,
		D_NPC+"/sentinel" : 1,
		]) );
        }
