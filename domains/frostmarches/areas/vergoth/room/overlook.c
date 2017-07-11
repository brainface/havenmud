#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("overlook");
  SetLong("This room appears to have been very similiar to the dining "
	"room.  The walls were made of glass but seem to have been shattered "
	"and melted all over the hot and blackened floor.  It seems as "
	"though some great battle happened here.  From this height all of "
	"Kailie is visible.  No thought comes to mind what could have "
	"caused this kind of damage.  The stairs are down from here.");
  SetItems( ([  "floor" : "The floor is hot to touch and black from being "
		"under extreme heat.",
	"room" : "The room appears to be badly damaged.  The glass walls are "
		"melted all over the blackened floor which is still very hot "
		"to the touch.  It is difficult to walk here because the "
		"floor is so warm.  There are a few piles of ashes that might "
		"of once been furniture.",
	({"wall","walls"}) : "The walls were made of glass at some point.  "
		"They have since been shattered and melted onto "
		"the floor of this overlook.",
	({"stairs","staircase"}) : "The staircase is down.",
	]) );
  SetItemAdjectives( ([ "wall" : ({"glass","shattered"}),
	"floor" : ({"hot","blackened"}),
	]) );			
  SetDomain("FrostMarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The winds whistles very loudly here without "
	"walls." ]) );  
  SetSmell( ( [ "default" : "This room smells of burnt wood." ]) );
  SetExits( ([ "down" : V_ROOM + "et3" ]) );
}