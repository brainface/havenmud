#include <lib.h>
inherit LIB_ROOM;
#include "../goblin.h"
 
static void create() {
room::create();
SetDomain("WestWood");
SetShort("a beaten trail");
SetLong("This trail meanders farther west away from the cobblestone road.  "
	"The trail is beaten into the ground suggesting that it is highly "
	"used.  Evergreen trees flourish to the north and south and slightly "
	"to the northwest lies a small lake.  The trail leads northwest, "
	"west, and east returning back to the cobblestone road.");
SetItems( ([
	({ "trail","road","ground","path" }) : (: GetLong :),
	({ "trees","tree" }) :
		"The beautiful evergreens flourish in the fertile "
		"atmosphere of the WestWood, growing close to the "
		"road.",
	({ "lake" }) : "The lake is very smooth and clear.  The water "
		"is so smooth and clear that the bottom can be seen.  "
		"There isnt anything in the bottom other than plants.",
	({ "plant","plants","reed","reeds" }) : "The plants in the "
		"bottom of the lake are nothing more than smalls reeds "
		"that grow well in wet enviroment of the lake.  They "
		"stand very tall and are a very light, almost "
		"translucent, shade of green.",
	]) );
SetItemAdjectives( ([
	"trail" : "beaten",
	"tree" : "evergreen",
	"path" : "forest",
	"plant" : "lake",
	]) );
SetListen( ([
	"default" : "Watery noises of splashing come from the west.",
	]) );
SetSmell( ([
	"default" : "The air smells of evergreen trees.",
	]) );
SetExits( ([
	"west" : G_ROOM + "camp_road_15",
	"northwest" : G_ROOM + "camp_road_03",
	"east" : G_ROOM + "camp_road_01",
	]) );
SetInventory( ([
	G_NPC + "goblin_wanderer" : 1,
	]) );
}