//  Malveillant Marketplace room 3
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
     "Shops of all size and variety nestle together in an outer ring which "
     "looks in on the center courtyard. The wide path is covered in a soft "
     "moss and wild vines that spill over the half-wall that encloses the "
     "courtyard. It stops here at an upscale boutique before curving to the "
     "northwest and southwest. An elegant sign graces the front of the "
     "building here."
     );
  SetListen( ([
     "default" : "The soft murmur of voices floats in and out of the shops.",
     ]) );
  SetSmell( ([
     "default" : "Fresh cloth and crisp linens give the air a clean scent.",
     ]) );
  SetItems( ([
     ({"area", "market", "marketplace"}) : (:GetLong:),
     ({"path"}) : 
    	 "The moss covered path curves towards the northeast and southeast.",
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
     ({"shop", "shops", "store", "building", "boutique", "clothier"}) :
         "A charming boutique rests at this part of the marketplace, boasting "
         "the finest clothier in all of Malveillant. The building is two "
         "stories.",
     ({"sign"}) :
     	 "An elegantly carved and lettered sign which reads: Madame Lavista's "
     	 "Boutique. A small sign attached to it points towards a hatter upstairs "
     	 "from the clothier.",
     ]) );
  SetItemAdjectives( ([
     "path" : ({"covered", "curved", "wide"}),
     "archway" : ({"carved", "obsidian"}),
     "walls" : ({"half", "circular", "obsidian", "carved", "rounded"}),
     "ground" : ({"mossy", "covered", "moss-covered"}),
     "moss" : ({"soft", "green", "pale", "dark"}),
     "vines" : ({"climbing", "clinging", "overgrown"}),
     "obsidian" : ({"black", "smooth"}),
     "sign" : ({"elegant", "carved"}),
     "shop" : ({"charming", "two-story"}),
     ]) );
  SetInventory( ([
     ]) );
  SetExits( ([
     "northwest" : MAL_ROOMS3 + "market2",
     "southeast" : MAL_ROOMS3 + "market4",
     ]) );
  SetEnters( ([
     "shop" : MAL_ROOMS3 + "clothier"
      ]) );
    
}

