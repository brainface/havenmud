/* a small pasture
   kyla 1-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small pasture");
SetDomain("Valley");
  SetClimate("temperate");
  SetInventory( ([
        PASTURE_NPC + "llama" : 2,
              ]) );
  SetExits( ([
        "east" : MANSION_ROOMS + "moat1",
        "north" : MANSION_ROOMS + "pasture4",
        "northeast" : MANSION_ROOMS + "moat2",
            ]) );
  SetSmell( ([
      "default" : "The long grass of the pasture smells fresh and clean.",
           ]) );
  SetListen( ([
      "default" : "The sound of mooing and stomping can be heard in the "
                  "distance.",
            ]) );
  SetLong("This part of the pasture doesn't look like it gets used too "
          "often. The grass is longer and is not very trampled. There is "
          "a moat to the east and to the west there is what appears to be "
         "the side of a building. The pasture goes on to the north and "
        "there appears to be more animals.");
  SetItems( ([
        "grass" : "The grass here seems healthier then the grass in the "
                  "rest of the pasture.",
        "moat" : "The moat can only be seen vaguely in the distance.",
      ({"side of building", "wall", "side", "building"}) : "This is the wall to a "
                                  "large wooden building.",
         ]) );
  }
