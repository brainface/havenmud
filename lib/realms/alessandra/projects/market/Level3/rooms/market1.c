//  Malveillant Marketplace room 1
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
     "default" : "Voices spill out from the many shops in the marketplace.",
     ]) );
  SetSmell( ([
     "default" : "It smells strongly of freshly baked bread here.",
     ]) );
  SetItems( ([
     ({"area", "market", "marketplace"}) : (:GetLong:),
     ({"path"}) : 
    	 "The path is covered with moss and creeping vines. It curves "
    	 "towards the northeast and southwest.",
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
         "shop, and through the freshly washed windows a myriad of goods "
         "neatly line shelves.",
     ({"sign"}) :
     	 "This large painted sign proclaims this shop as the Malveillant General "
     	 "Store, owned and operated by the Rifalia family.",
     ({"doorway"}) :
     	 "During the day the door is always open to prospective customers.",
     ({"goods", "shelves"}) :
     	 "Perhaps you could get a closer look by entering the shop.",
     ({"basket", "baskets"}) :
     	 "These handwoven baskets line the inside of the cart and hang "
     	 "carefully from the sides. Nearly all are overflowing with bread "
     	 "and exotic fruits.",
     ({"bread"}) :
     	 "Long slender baguettes, small round loaves, breads filled with "
     	 "herbs, the selection is tantalizing.",
     ({"fruit", "fruits"}) :
     	 "Each and every piece looks as though it was hand picked and pampered.",
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
     "bread" : ({"fresh", "baked"}),
     "fruit" : ({"exotic"}),
     ]) );
  SetInventory( ([
     MAL_NPC3 + "bread_ven" : 1,
     MAL_OBJ3 + "bread_cart" : 1,
     ]) );
  SetExits( ([
    "northeast" : MAL_ROOMS3 + "marketentrance",
    "southwest" : MAL_ROOMS3 + "market2",
    ]) );
  SetEnters( ([
     "shop" : MAL_ROOMS3 + "general",
     ]) );
}
  

