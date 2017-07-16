#include <lib.h>
inherit LIB_ROOM;
#include "../goblin.h"
 
static void create() {
room::create();
SetDomain("WestWood");
SetShort("a beaten trail");
SetLong("This trail meanders farther away from the cobblestone road.  "
	"The trail is beaten into the ground suggesting that it is highly "
	"used.  Evergreen trees flourish to the north and west while off "
	"to the south and east is a lake.  The trail leads southwest "
	"and northeast returning back to the cobblestone road.");
SetItems( ([
	({ "trail","road","ground","path" }) : (: GetLong :),
	({ "trees","tree" }) :
		"The beautiful evergreens flourish in the fertile "
		"atmosphere of the WestWood, growing close to the "
		"trail.",
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
	]) );
SetListen( ([
	"default" : "Low voices can be heard to the north and children's "
		"voices can be heard to the southwest.",
	]) );
SetSmell( ([
	"default" : "The smell of smoke lightly permeates the air.",
	]) );
SetExits( ([
	"southwest" : G_ROOM + "camp_road_08",
	"northeast" : G_ROOM + "camp_road_06",
	]) );
}