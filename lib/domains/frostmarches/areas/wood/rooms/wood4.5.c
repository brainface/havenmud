/* beneath the willow
   Ela 10/10/98
*/

#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("beneath the willow");
  SetDomain("FrostMarches");
  SetClimate("temperate");
  SetObviousExits("out");
  SetExits( ([
       "out" : WOOD_ROOMS + "wood4",
       ]) );
  SetLong("Curtains of cascading greenery surround the area, " 
       "creating a peaceful room. The shadows provide a "
       "safe haven. Soft moss blankets the ground and makes it "
       "an extremely desirable place to lay down and rest "
       "a while.");
  SetItems( ([
        ({"shadows","shadow","camoflage"}) : "The shadows provide "
                  "a natural camoflage.",
        ({"moss","ground"}) : "Thick green moss carpets and "
                  "cusions the ground.",
        ({"greenery","foilage"}) : "The elegantly sweeping foilage "
               "gently brushes the ground, creating an "
               "enclosed santuary.",
        ({"willow","tree","willow tree"}) : "The ancient tree "
               "provides a safe hiding place.",
        "wood" : "The forbidding wood surrounds this tiny spot of "
               "tranquility.",
        ]) );
  SetSmell( ([
   "default" : "There is the distinct aroma of wet earth and trees.",
    ]) );
  SetListen( ([
    "default" : "The sound of gently rustling foilage is very peaceful.",
    ]) );
  SetInventory( ([
     WOOD_NPC + "unicorn" : 1,
      ]) );
}
