#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
	 room::create();
	 SetClimate("indoors");
	 SetAmbientLight(15);
	 SetShort("a small tavern");
	 SetLong(
	   "This tavern is a small room that could have once been a niche in the "
	   "wall. Small wooden stools line up against a bar set into the wall, "
	   "and the room has a dim, dirty quality that seems out of place in the "
	   "shining and clean city of Glimmerdin. Dusty wooden boards line the "
	   "walls in some effort to cover the rough rocky stone."
	   );
  SetProperty("no teleport",1);
  SetProperty("no conjuring",1);
  SetItems( ([
	   ({ "wall", "walls", "stone", }) : 
	       "The walls are rough and jagged rock, far from the polished "
	       "and well crafted efforts elsewhere in the city.",
	   ({ "stool", "stools" }) :
	       "The stools are scraggly looking wooden chairs that don't seem "
	       "to be very sturdy.",
	   ({ "bar" }) :
	       "The bar is a wooden but unpolished structure that is installed "
	       "on the wall.  It seems to groan under the weight of patrons' "
	       "drinks.",
	   ({ "boards", "board" }) :
	       "The boards seem to patch over the rough rock, but cannot cover "
	       "it completely, making the tavern look slipshod.",
	   ]) );
	SetItemAdjectives( ([
	  "wall" : ({ "rough", "rocky", }),
	  "stool": ({ "small", "wooden", }),
	  "board": ({ "dusty", "wooden", }),
	  ]) );
  SetExits( ([
    "out" : G_ROOM "tunnel2",
    ]) );
  SetSmell( ([
    "default" : "The room smells of stale beer.",
    ]) );
  SetListen( ([
    "default" : "Quiet conversation whispers all around.",
    ]) );
  SetInventory( ([
    G_NPC "tabitha" : 1,
    G_NPC "housecat" : 1,
    ]) );
}
  	
  	
  	
  	
  	
