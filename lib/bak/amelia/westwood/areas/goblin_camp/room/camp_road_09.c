#include <lib.h>
inherit LIB_ROOM;
#include "../goblin.h"
 
static void create() {
room::create();
SetDomain("WestWood");
SetShort("a large clearing");
SetLong("This large clearing has become a full blown goblin camp along the "
	"edge of the lake.  It is very clear and open of trees.  The "
	"lake is nearby to the east.  The trail leads south and north.  To "
	"the west is a large tent.  This would appear to be the home of "
	"whatever leads this small camp.");
SetItems( ([
	({ "trees","tree" }) :
		"The beautiful evergreens flourish in the fertile "
		"atmosphere of the WestWood, growing a long distance "
		"from the camp.",
	({ "lake" }) : "The lake is very smooth and clear.  The water "
		"is so smooth and clear that the bottom can be seen.  "
		"There isnt anything in the bottom other than plants.",
	({ "clearing" }) : (: GetLong :),
	({ "camp" }) : "The camp is a small goblin camp.  There are tents "
		"scattered about and small fires set up in short intervals.  "
		"Small patrols of goblins wander about the camp.",
	({ "goblin","goblin" }) : "The goblins are soldiers and range in "
		"height from three feet to four feet.",
	({ "tent" }) : "The tent is green in color and stands about seven "
		"feet tall at its center.  It blends well into the "
		"surrounding trees.  There is an entrance to the tent here "
		"and the inside is very dinly lit.",
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
	G_NPC + "goblin_merc" : 2,
	G_NPC + "goblin_soldier2" : 3,
	]) );
SetListen( ([
	"default" : "The sounds of people bustling about and breaking camp "
		"surround the area drowning out all other sound.",
	]) );
SetSmell( ([
	"default" : "The air smells of rotten fish.",
	]) );
   SetEnters( ([
            "tent" : G_ROOM + "camp_road_10",
    ]) );
SetExits( ([
	"north" : G_ROOM + "camp_road_08",
	"south" : G_ROOM + "camp_road_11",
	]) );
}
