#include <lib.h>
inherit LIB_ROOM;
#include "../goblin.h"
 
static void create() {
room::create();

SetShort("a large clearing");
SetLong("This beaten trail opens up into a large clearing along the "
	"edge of the lake.  It appears to be a nice place for children to "
	"play because the clearing is covered in a soft grass.  There "
	"is a camp of goblins set up along the shore of the lake.  "
	"It is very clear and open of trees.  The lake is nearby "
	"to the east.  The trail leads south and northeast.");
SetItems( ([
	({ "trail","road","ground","path" }) : (: GetLong :),
	({ "trees","tree" }) :
		"The beautiful evergreens flourish in the fertile "
		"atmosphere of the WestWood, growing close to the "
		"trail.",
	({ "lake" }) : "The lake is very smooth and clear.  The water "
		"is so smooth and clear that the bottom can be seen.  "
		"There isn't anything in the bottom other than plants.",
	({ "clearing" }) : (: GetLong :),
	({ "camp" }) : "The camp is a small goblin camp.  There are tents "
		"scattered about and small fires set up in short intervals.  "
		"Small patrols of goblins wander about the camp.",
	({ "goblin","goblin" }) : "The goblins are soldiers and range in "
		"height from three feet to four feet.  They are running "
		"about preparing for something.",
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
	"clearing" : "large",
	"goblin" : ({ "small","patrol","patrols"}),
	]) );
SetInventory( ([
	G_NPC + "goblin_boy" : 1,
	G_NPC + "goblin_girl" : 1,
	G_NPC + "goblin_warren" : 1,
	]) );
SetListen( ([
	"default" : "The sounds of a camp sound very close at hand.",
	]) );
SetSmell( ([
	"default" : "The air smells of rotten fish.",
	]) );
SetExits( ([
	"south" : G_ROOM + "camp_road_09",
	"northeast" : G_ROOM + "camp_road_07",
	]) );
}