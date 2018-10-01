//  Malveillant Marketplace room 7
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
     "The wide path of the marketplace curves here to the northeast and "
     "southwest. Shops of all size and variety nestle together in an outer "
     "ring which looks over the half-wall into the center courtyard. It "
     "stops here at the Malveillant smithy before curving to the northwest "
     "and southwest."
     );
  SetListen( ([
     "default" : "Many voices plying wares can be heard in all directions.",
     ]) );
  SetSmell( ([
     "default" : "The air reeks of freshly smelted metals and new leather.",
     ]) );
  SetItems( ([
     ({"area", "market", "marketplace"}) : (:GetLong:),
     ({"path"}) : 
    	 "The moss covered path curves towards the northwest and southeast.",
     ({"courtyard"}) :
    	 "The courtyard can be seen just beyond the half wall which circles it. "
    	 "Benches make it an inviting place to rest after a day of shopping.",
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
     ({"shop", "shops", "store", "building", "smithy"}) :
         "The smithy rests here, nestled between the other shops which make "
         "up the marketplace.",
     ]) );
  SetItemAdjectives( ([
     "path" : ({"covered", "curved", "wide"}),
     "archway" : ({"carved", "obsidian"}),
     "walls" : ({"half", "circular", "obsidian", "carved", "rounded"}),
     "ground" : ({"mossy", "covered", "moss-covered"}),
     "moss" : ({"soft", "green", "pale", "dark"}),
     "vines" : ({"climbing", "clinging", "overgrown"}),
     "obsidian" : ({"black", "smooth"}),
     ]) );
  SetInventory( ([
     ]) );
  SetExits( ([
     "northwest" : MAL_ROOMS3 + "marketentrance",
     "southeast" : MAL_ROOMS3 + "market6",
     ]) );
  SetEnters( ([
     "smithy" : MAL_ROOMS3 + "smithy",
     ]) );      

}

