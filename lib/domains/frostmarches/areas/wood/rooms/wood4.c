/* quiet glen
    Ela 10/7/98
*/

#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;


static void create() {
  room::create();
  SetShort("a quiet glen");
  SetDomain("FrostMarches");
  SetClimate("temperate");
  SetObviousExits("north, northeast, east");
  SetExits( ([
        "north" : WOOD_ROOMS + "wood3",
        "east" : WOOD_ROOMS + "wood5",
        "northeast" : WOOD_ROOMS + "wood2",
        ]) );
  SetLong("A secluded glen is free of the abundant briars at home "
        "in the rest of the dark wood. Shadows here provide a "
        "safe haven rather than ominous warning. The limbs of "
        "cascading greenery of an ancient willow tree provides "
        "a shadow-laden shelter. Soft moss lines the ground.");
  SetItems( ([
         ({"shadows","shadow","camoflage"}) : "The shadows provide "
                   "camoflage for the glen's ihabitants.",
         ({"most","ground"}) : "Thick green moss carpets and "
                   "cusions the ground.",
         ({"limb","limbs","branches","branch"}) : "The elegantly "
                "sweeping branches of the willow gently brush "
                "the mossy ground.",
         ({"greenery","foliage"}) : "Upon closer examination, "
                "an opening in the dense foliage is visible.",
         ({"willow","tree","willow tree"}) : "The ancient tree, "
                   "with its harboring branches, could provide "
                   "a safe hiding place.",
         "wood" : "The forbidding wood surrounds this tiny spot of "
                   "tranquility.",
         "glen" : "The glen looks much safer than the surrounding "
                   "wood.",
         "shade" : "The shade cast by the willow provides an ideal "
                   "camoflage.",
         "shelter" : "The dense greenery create a small shelter.",
         ]) );
  SetEnters( ([
   ({"greenery","foliage"}) : WOOD_ROOMS + "wood4.5",
     ]) );
  SetSmell( ([
    "default" : "There is the distinct aroma of wet earth and trees.",
     ]) );
  SetListen( ([
     "default" : "The sound of gently rustling leaves can be heard.",
     ]) );
  SetInventory( ([
       ]) );
}
