#include <lib.h>
inherit LIB_ROOM;
#include "../goblin.h"
 
static void create() {
room::create();
SetDomain("WestWood");
SetShort("a beaten trail");
SetLong("This trail meanders farther away from the cobblestone road.  "
	"The trail is beaten into the ground suggesting that it is highly "
	"used.  Evergreen trees flourish to the south while off to the "
	"north is a lake.  The trail leads west and east returning back "
	"to the cobblestone road.");
SetItems( ([
	({ "trail","road","ground","path" }) : (: GetLong :),
	({ "trees","tree" }) :
		"The beautiful evergreens flourish in the fertile "
		"atmosphere of the WestWood, growing close to the "
		"trail.",
	({ "lake" }) : "The lake is very smooth and clear.  The water "
		"is so smooth and clear that the bottom can be seen.  "
		"There isn't anything in the bottom other than plants.",
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
	"road" : "cobblestone",
	]) );
SetListen( ([
	"default" : "Low voices can be heard to the east and west.",
	]) );
SetSmell( ([
	"default" : "The smell of smoke lightly permeates the air.",
	]) );
SetExits( ([
	"west" : G_ROOM + "camp_road_12",
	"east" : G_ROOM + "camp_road_14",
	]) );
}