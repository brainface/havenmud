/*  Mahkefel 2017
 *  Sock seller for the marketplace
 *
 */
#include <lib.h> 
//#include "../mal.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetAmbientLight(20);
  SetClimate("indoors");
  SetShort("the Darned Rat");
  SetLong(
    "Much longer than the tiny storefront suggests, the floor of this shop "
    "must lead deep into the cavern of Malveillant. Socks hang in singles, "
    "pairs, and triplets from a multitude of clothesracks or from twine set "
    "in the ceiling above, stick out of drawers, and sit on shelves and in "
    "neatly stacked piles on the floor. A bay display window reveals "
    "the occasional passerby through gaps in the pedal panoply. "
    "A tiny counter near the narrow door leading out holds a mechanical till."
     );
  SetListen( ([
     "default" : "Muffled click-clacks of the tiller or soft footstep "
     "occasionally interrupt the silence.",
     ]) );
  SetSmell( ([
     "default" : "The scent of fresh washed wool and mahogany hangs "
       "in the air.",
     ]) );
  SetItems( ([
     ({"room", "shop", "store", "space"}) : (:GetLong:),
     ({"counter"}) :
        "The ebony counter is just wide enough for a single skaven shopkeep "
        "to stand behind. A geary gnomish till is screwed securely into the "
        "top.",
     ({"socks", "panoply"}) :
        "Striped, dotted, plain and darned; silk, linen and lace; dull gray "
        "vibrant red, every permutation of sock seems on display.",
     ({"singles", "pairs", "triplets" }) :
        "The proprietor of the shop seems to find value even in singletons. "
        "Pairs with a single matching tail sheathe seem common in the mix as "
        "well.",
     ({"racks", "clothesracks", "hatracks"}) :
       "Long clothes racks and repurposed hatracks fill every spare bit of space",
     ({"ceiling", "twine"}) :
       "The mahogany ceiling features carvings of dancing elves and skavens "
       "admist trees and stalactites. Nails stuck in the ceiling hold dangling "
       "twine, which in turn holds a multitude of various socks, creating "
       "colourful curtains below.",
     ({"wall","walls", "panelling"}) :
        "Aged mahogany panelling gives the room a comfortable dark ambiance.",
     ({"shelf", "shelves"}) :
         "Long shelves along the wall hold slightly organized piles of socks "
         "of every stripe and colour.",
     ({"floor", "ground"}) :
         "The hardwood floor is worn and scratched from years of footsteps.",
     ({"cavern"}) :
         "Stone glanced through the occasional warp and gap in the panelling "
         "of the walls hints at the surrounding cavern.",
     ({"drawers"}) :
         "Chest of drawers and orphan drawers and dressers all hold what are "
         "most likely more socks.",
     ({"piles"}) :
         "Neat piles of freshly tailored socks in the latest fashions sit in "
         "corners between dressers and shelves.",
     ({"window","gaps"}) :
        "Dapper dark elves, skulking skaven, guileless gelflings or whatever "
        "stranger things stalk the market are rather occluded by the wares of "
        "the shop."
     ]) );
  SetItemAdjectives( ([
    // TODO: "bunchers"
     /*"counter" : ({"spotless", "wooden", "wood"}),
     "wall" : ({"bare"}),
     "shelf" : ({"empty", "carved", "wooden", "wood"}),
     "floor" : ({"spotless"}),*/
     ]) );
  SetInventory( ([
    // 1 sock seller
     ]) );
  SetExits( ([
     //"out" : MAL_ROOMS3 + "market2",
     ]) );

}

