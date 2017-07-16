#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("overlook dining");
  SetLong("The walls of this dining room are not of stone as the rest of the "
	"tower is but made of some sort of glass instead.  The floor is the "
	"only part of this room that is made from stone.  It is carpeted "
	"with the soft fur of some small animal.  There is a table here with "
	"six chairs.  The stairs are down from here.");
  SetItems( ([  "tower" : "This appears to be the first spire of the tower.",
	"spire" : "The tower has three spires at the top.",
	"top" : "The top of the tower is not viewable from here.  From "
		"the outside, it stretched to high to see.",
	"room" : "With the walls being made from a glass, one might be "
		"inclined to think the owner is very strange.",
	({"wall","walls","glass"}) : "The walls are made of a sort of "
		"glass.  It is impossible to break and seems to be more "
		"like iron than glass.  All of Kailie is viewable from here.",
	"floor" : "The floor is carpeted in some sort of animal fur.",
	({"animal","carpet"}) : "The carpet is made from the soft fur of "
		"a small animal.  It is colored in light hues of gray "
		"and white.",
	"table" : "The table is carved from an exotic wood in the "
		"form of a dragon.  The wings spread out and form "
		"eating surfaces.",
	({"chair","chairs"}) : "The chairs are carved from an exotic "
		"wood that does not appear to be from Kailie.  They are "
		"cushioned with a black velvet and have very high backs.",
	({"stairs","staircase"}) : "The staircase is down from here.",
	"wood" : "The wood that most of the furniture appears to be "
		"made from a very dark wood, almost a dark blue "
		"color.  The grain is very tight and it appears that "
		"the wood is very strong and resilient.",
	]) );
  SetItemAdjectives( ([ "room" : ({"dining"}),
	"wall" : ({"glass"}),
	"floor" : ({"carpeted","soft","fur","small","stone"}),
	"chair" : ({"carved","wood","cushioned"}),
	"wood" : ({"exotic","resilient","dark","blue","strong"}),
	"table" : ({"carved","wood","dragon"}),
	"carpet" : ({"animal","fur","soft","white","gray"}),
	]) );
  SetInventory( ([
	V_NPC + "kobold" : 1,
	]) );
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The dining room is very quiet." ]) );  
  SetSmell( ( [ "default" : "This room smells slightly of old spices." ]) );
  SetExits( ([ "down" : V_ROOM + "wt3" ]) );
}