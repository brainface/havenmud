//  Merchant Leaders room in Marketplace
//  Alessandra 2009

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetAmbientLight(15);
  SetClimate("indoors");
  SetShort("a dim backroom");
  SetLong(
     "A large elegant desk sits in the center of this room, behind it rests "
     "an overstuffed chair, with two smaller chairs closer to the exit. "
     "Aside from the sparse furniture this room is completely bare. The walls "
     "have been painted a dark tan color, and the floor is comprised of "
     "perfectly straight wooden planks. An exit to the north heads back into "
     "the jewelry shop."
     );
  SetSmell( ([
     "default" : "The air reeks of smoke.",
     ]) );
  SetListen( ([
     "default" : "The sounds of people can be heard outside.",
     ]) );
  SetItems( ([
     ({"room", "backroom"}) : (:GetLong:),
     ({"desk"}) :
     	 "Carved from a dark wood, this elegant desk is quite large and "
     	 "imposing.",
     ({"chair", "chairs"}) :
     	 "An overstuffed chair rests behind the desk, large and comfortable "
     	 "looking. It is covered in a fine black leather. Two smaller chairs "
     	 "made of wood sit in front of the desk.",
     ({"floor", "ground", "planks"}) :
     	 "The floor is made of wooden planks, which are perfectly straight "
     	 "and made of wood that is flawless. They have been polished to a "
     	 "shine.",
     ({"wall", "walls"}) :
     	 "The walls have been painted a dark tan color and are completely bare "
     	 "otherwise.",
     ({"exit"}) : 
     	 "The jewelry shop lies to the north.",
     ]) );
  SetItemAdjectives( ([
     "desk" : ({"carved", "wood", "large", "imposing", "elegant"}),
     "chair" : ({"large", "small", "overstuffed", "leather", "wooden"}),
     "floor" : ({"wood", "straight", "flawless", "polished"}),
     "wall" : ({"painted", "tan", "bare"}),
     ]) );
  SetInventory( ([
     MAL_NPC3 + "merch_lead" : 1,
     ]) );
  SetExits( ([
     "north" : MAL_ROOMS3 + "jeweler",
     ]) );



}
