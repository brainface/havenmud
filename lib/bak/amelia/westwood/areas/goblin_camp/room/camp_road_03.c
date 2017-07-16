#include <lib.h>
inherit LIB_ROOM;
#include "../goblin.h"
 
static void create() {
room::create();
SetDomain("WestWood");
SetShort("a beaten trail");
SetLong("This trail meanders farther north away from the cobblestone road.  "
	"The trail is beaten into the ground suggesting that it is highly "
	"used.  Evergreen trees flourish to the east while off to the west "
	"lies a small lake.  The trail leads north and southeast "
	"returning back to the cobblestone road.");
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
	"plant" : "lake",
	"tree" : "evergreen",
	"path" : "forest",
	"lake" : "small",
	]) );
SetInventory( ([
	G_NPC + "goblin_merc" : 2,
	]) );
SetListen( ([
	"default" : "Watery noises of splashing come from the west.",
	]) );
SetSmell( ([
	"default" : "The air smells of evergreen trees.",
	]) );
SetExits( ([
	"north" : G_ROOM + "camp_road_04",
	"southeast" : G_ROOM + "camp_road_02",
	]) );
}
