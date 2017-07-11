//  Malveillant Marketplace room 5
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
     "ring which looks over the half-wall into the center courtyard. A large "
     "sign hangs above a shop doorway here. The marketplace is busy all day "
     "with the buzz of citizens and vendors."
     );
  SetListen( ([
     "default" : "Many voices plying wares can be heard in all directions.",
     ]) );
  SetSmell( ([
     "default" : "Scents ranging from freshly baked bread to the crisp smell "
       "of new clothing mingle in the air.",
     ]) );
  SetItems( ([
     ({"area", "market", "marketplace"}) : (:GetLong:),
     ({"path"}) : 
    	 "The moss covered path curves towards the northeast and southwest.",
     ({"courtyard"}) :
    	 "The courtyard can be seen just beyond the half wall which circles it. "
    	 "Benches make it an inviting place to rest after a day of shopping.",
     ({"walls", "wall"}) : 
    	 "This is a half-wall, carved from obsidian, which partially "
         "encloses the courtyard. Lush, wild vines climb over the wall "
         "and creep out to the path.",
     ({"ground", "floor"}) : 
    	 "The ground is covered in soft moss and overgrown clinging vines.",
     ({"moss"}) : 
    	 "The soft moss varies from a pale to dark green.",
     ({"vines", "vine"}) :
    	 "Clinging vines scale the wall and spill over into the courtyard.",
     ({"obsidian"}) :
    	 "A stone used frequently by the dark-elves, it is jet black in color "
    	 "and smooth and cool to the touch.",
     ({"shop", "shops", "store", "building", "buildings"}) :
         "The shops all range in size, but seem settled together in some "
         "greater order. A sign hangs above the doorway to this particular "
         "shop, and it appears there is a second story.",
     ({"sign"}) :
     	 "This large painted sign reads: All things Arcane! A smaller sign "
     	 "above it claims the two story building has a gem shop in the upper "
     	 "quarter.",
     ({"doorway"}) :
     	 "During the day the door is always open to prospective customers.",
     ]) );
  SetItemAdjectives( ([
     "path" : ({"covered", "curved", "wide"}),
     "archway" : ({"carved", "obsidian"}),
     "walls" : ({"half", "circular", "obsidian", "carved", "rounded"}),
     "ground" : ({"mossy", "covered", "moss-covered"}),
     "moss" : ({"soft", "green", "pale", "dark"}),
     "vines" : ({"climbing", "clinging", "overgrown"}),
     "obsidian" : ({"black", "smooth"}),
     "sign" : ({"large", "painted"}),
     ]) );
  SetInventory( ([
     ]) );
  SetExits( ([
     "northeast" : MAL_ROOMS3 + "market6",
     "southwest" : MAL_ROOMS3 + "market4",
     ]) ); 
  SetEnters( ([
     "shop" : MAL_ROOMS3 + "magic",
     ]) );

}

