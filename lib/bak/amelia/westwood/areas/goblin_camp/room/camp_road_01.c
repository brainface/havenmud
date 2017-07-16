#include <lib.h>
inherit LIB_ROOM;
#include "../goblin.h"
 
static void create() {
room::create();
SetDomain("WestWood");
SetShort("a beaten trail");
SetLong("This trail meanders farther west away from the cobblestone road.  "
	"The trail is beaten into the ground suggesting that it is highly "
	"used.  Evergreen trees flourish to the north and south, while the "
	"trail continues its trek to the west and east.");
SetItems( ([
	({ "trail","road","ground","path" }) : (: GetLong :),
	({ "trees","tree" }) :
		"The beautiful evergreens flourish in the fertile "
		"atmosphere of the WestWood, growing close to the "
		"road.",
	]) );
SetItemAdjectives( ([
	"trail" : "beaten",
	"tree" : "evergreen",
	"path" : "forest",
	]) );
SetListen( ([
	"default" : "Watery noises of splashing come from the west.",
	]) );
SetSmell( ([
	"default" : "The air smells of evergreen trees.",
	]) );
SetExits( ([
	"west" : G_ROOM + "camp_road_02",
	"east" : "/domains/westwood/virtual/westwood/9,6",
	]) );
}
