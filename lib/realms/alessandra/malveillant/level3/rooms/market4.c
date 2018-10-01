//  Malveillant Marketplace room 4
//  Alessandra 2009

#include <lib.h>
#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetAmbientLight(20);
  SetClimate("underground");
  SetShort("the marketplace");
  SetLong(
     "The marketplace is the hub of activity in Malveillant, constantly alive "
     "with the chatter of vendors and shoppers alike. Shops of all size and "
     "color nestle together in an outer ring which looks in on the center "
     "courtyard. The path is wide and covered in a soft moss and wild vines "
     "which spill over the half-wall that encloses the courtyard. The path "
     "stops at a shop here which appears to be a jeweler, before curving off "
     "towards other shops northeast and northwest." 
     );
  SetListen( ([
     "default" : "All around, the sounds of bartering for goods can be heard.",
     ]) );
  SetSmell( ([
     "default" : "The breeze carries a faint scent of fresh flowers.",
     ]) );
  SetItems( ([
     ({"area", "market", "marketplace"}) : (:GetLong:),
     ({"path"}) : 
    	 "The path is covered with moss and creeping vines. It curves "
    	 "towards the northwest and northeast.",
     ({"courtyard"}) :
         "The courtyard can be seen just beyond the half wall which circles "
         "it. ",
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
     ({"shop", "shops", "store", "building", "jeweler"}) :
         "Nestled amongst the other shops of the marketplace, sits this which "
         "appears to be a dealer in fine jewels.",
     ]) );
  SetItemAdjectives( ([
     "path" : ({"covered", "curved", "wide"}),
     "walls" : ({"half", "circular", "obsidian", "carved", "rounded"}),
     "ground" : ({"mossy", "covered", "moss-covered"}),
     "moss" : ({"soft", "green", "pale", "dark"}),
     "vines" : ({"climbing", "clinging", "overgrown"}),
     "obsidian" : ({"black", "smooth"}),
     ]) );
  SetInventory( ([
     ]) );
  SetExits( ([
     "northwest" : MAL_ROOMS3 + "market3",
     "northeast" : MAL_ROOMS3 + "market5",
     ]) );
  SetEnters( ([
     "shop" : MAL_ROOMS3 + "jeweler",
     ]) ); 
    
}
