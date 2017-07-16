#include <lib.h>
inherit LIB_ROOM;
#include "../goblin.h"
 
static void create() {
room::create();
SetDomain("WestWood");
SetShort("a small clearing");
SetLong("This beaten trail opens up into a small clearing along the "
	"edge of the lake.  There is nothing here but the forest skirting "
	"along the edge of the clearing.  To the south and west lies the "
	"thick forest of evergreens and to the north is a lake.  The "
	"trail leads northwest and east.");
SetItems( ([
	({ "trail","road","ground","clearing","path" }) : (: GetLong :),
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
	"road" : "cobblestone",
	]) );
SetInventory( ([
	G_NPC + "goblin_merc" : 3,
	]) );
SetListen( ([
	"default" : "Voices and sounds of a camp sound nearby.",
	]) );
SetSmell( ([
	"default" : "The smell of smoke lightly permeates the air.",
	]) );SetExits( ([
	"northwest" : G_ROOM + "camp_road_11",
	"east" : G_ROOM + "camp_road_13",
	]) );
}