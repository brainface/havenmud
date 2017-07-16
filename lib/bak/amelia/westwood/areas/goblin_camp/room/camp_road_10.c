#include <lib.h>
inherit LIB_ROOM;
#include "../goblin.h"
 
static void create() {
room::create();
SetDomain("WestWood");
SetShort("the inside of a tent");
SetLong("This is the inside of a large tent.  It is very sparsely "
	"decorated and the floor is nothing more than packed dirt.  "
	"The canvas of the tent is green in color and very plain.  "
	"This would appear to be the home of whoever leads these "
	"goblins.");
SetItems( ([
	({ "tent" }) : (: GetLong :),
	({ "floor" }) : "The floor is nothing more packed dirt.",
	({ "wall","walls" }) : "The walls are made of a canvas that is "
		"green in color and not at all decorated.",
	({ "canvas" }) : "The canvas is very durable and thick.  It would "
		"appear that it could hold up to most weather and insulate "
		"against the cold and heat.",
	({ "goblin","goblins" }) : "The goblins are outside the tent.  None "
		"would seen brave enough to enter here.",
	]) );
SetItemAdjectives( ([
	"goblin" : ({ "brave"}),
	"wall" : "green",
	"dirt" : "packed",
	]) );
SetInventory( ([
	G_NPC + "orc_leader" : 1,
	]) );
SetListen( ([
	"default" : "The inside of the tent os very quiet.",
	]) );
SetSmell( ([
	"default" : "The air smells like moldy canvas that has been out in "
		"the weather too long.",
	]) );
SetExits( ([
	"out" : G_ROOM + "camp_road_09",
	]) );
}
