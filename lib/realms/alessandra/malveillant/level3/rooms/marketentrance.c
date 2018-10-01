//  Malveillant Marketplace entrance
//  Alessandra 2009

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  
  SetAmbientLight(20);
  SetClimate("underground");
  SetShort("entrance to the marketplace");
  SetLong(
     "The marketplace is the hub of activity in Malveillant, constantly "
     "alive with the chatter of vendors and shoppers alike. Shops of all "
     "size and variety nestle together in an outer ring which looks in "
     "on the center courtyard. The path is wide and covered in a soft "
     "moss and wild vines which spill over the half-wall that encloses "
     "the courtyard. The path curves toward the southeast and southwest, "
     "while an archway leads back out. "
     );
  SetListen( ([
     "default" : "The sounds of bartering and chatting fill the air.",
     ]) );
  SetSmell( ([
     "default" : "The aroma of freshly cut flowers lingers here.",
     ]) );
  SetItems( ([
     ({"area", "market", "marketplace"}) : (:GetLong:),
     ({"path"}) : 
    	 "The path is covered with moss and creeping vines. It curves "
    	 "towards the southeast and southwest or back through the archway "
    	 "into the courtyard.",
     ({"archway", "arch"}) : 
    	 "The archway is carved of the same smooth obsidian used in most of "
         "Malveillant. Vines wrap around and drape festively from the arch. "
         "It leads out to the courtyard.",
     ({"courtyard"}) :
    	 "The courtyard can be seen just beyond the half wall which circles it. "
    	 "From the courtyard, one can return to the other parts of Malveillant.",
     ({"walls", "wall"}) : 
    	 "This is a half-wall, carved from obsidian, which partially "
         "encloses the courtyard. Lush, wild vines spill over the wall "
         "and creep out to the path.",
     ({"ground", "floor"}) : 
    	 "The ground is covered in soft moss and overgrown clinging vines.",
     ({"moss"}) : 
    	 "The moss is soft and varies from a pale to dark green.",
     ({"vines", "vine"}) :
    	 "Small vines cling to the ground and walls, climbing over the wall "
    	 "and spilling into the courtyard.",
     ({"obsidian"}) :
    	 "A stone used frequently by the dark-elves, it is jet black in color "
    	 "and smooth and cool to the touch.",
     ({"shop", "shops", "ring"}) :
       "Various shops nestle together to form this marketplace.",
     ({"basket", "baskets"}) :
     	 "These handwoven baskets line the inside of the wagon, and hold many "
     	 "bunches of flowers of all variety.",
     ({"flower", "flowers"}) :
     	 "These would make gorgeous bouquets, as their vibrant colors are "
     	 "almost mesmorizing.",
     ]) );
  SetItemAdjectives( ([
     "path" : ({"covered", "curved", "wide"}),
     "archway" : ({"carved", "obsidian"}),
     "walls" : ({"half", "circular", "obsidian", "carved", "rounded"}),
     "ground" : ({"mossy", "covered", "moss-covered"}),
     "moss" : ({"soft", "green", "pale", "dark"}),
     "vines" : ({"climbing", "clinging", "overgrown"}),
     "obsidian" : ({"black", "smooth"}),
     "courtyard" : ({"center"}),
     "ring" : ({"outer"}),
     ]) );
  SetInventory( ([
     MAL_NPC3 + "flower_ven" : 1,
     MAL_OBJ3 + "flower_wagon" : 1,
     ]) );
  SetExits( ([
     "out" : MAL_ROOMS3 + "center3",
     "southeast" : MAL_ROOMS3 + "market7",
     "southwest" : MAL_ROOMS3 + "market1",
     ]) );
    
}

