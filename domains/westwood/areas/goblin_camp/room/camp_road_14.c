#include <lib.h>
inherit LIB_ROOM;
#include "../goblin.h"
 
static void create() {
room::create();

SetShort("a small clearing");
SetLong("This beaten trail opens up into a small clearing along the "
	"edge of the lake.  There is a campfire here that is still "
	"burning and crackling.  Evergreen trees flourish to the south "
	"while off to the north is the lake.  The trail leads west and "
	"east back to the cobblestone road.");
SetItems( ([
	({ "trail","road","ground","path" }) : (: GetLong :),
	({ "trees","tree" }) :
		"The beautiful evergreens flourish in the fertile "
		"atmosphere of the WestWood, growing close to the "
		"trail.",
	({ "lake" }) : "The lake is very smooth and clear.  The water "
		"is so smooth and clear that the bottom can be seen.  "
		"There isnt anything in the bottom other than plants.",
	({ "fire","campfire" }) : "The fire is very small and "
		"dug into a pit.  It crackles and every once in a "
		"while the flames lick high into the air, as though "
		"trying to reach the heavens.  The pit is lined with "
		"small rocks and is covered in embers at the bottom.",
	({ "flame","flames" }) : "The flames from the fire lick high "
		"the air.",
	({ "ember","embers" }) : "The embers are glowing bright red in "
		"the bottom of the fire pit.",
	({ "rock","rocks" }) : "The rocks line the bottom of the fire pit "
		"protecting everything else from catching fire.",
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
	G_NPC + "goblin_soldier" : 2,
	G_OBJ + "rabbit" : 1,
	G_OBJ + "spit" : 1,
	]) );
SetListen( ([
	"default" : "Watery noises of splashing come from the north.",
	]) );
SetSmell( ([
	"default" : "The air smells of roasted rabbit.",
	]) );
SetExits( ([
	"west" : G_ROOM + "camp_road_13",
	"northeast" : G_ROOM + "camp_road_15",
	]) );
}