#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetAmbientLight(5);
    SetClimate("underground");
    SetShort("a passage");
    SetLong("This passage leads north and east.  It is somewhat wet, "
            "with water seeping in from both sides.  The passage is "
            "about ten feet across, and is composed of roughly chiseled "
            "stone.  There are some small footprints heading north to "
            "a small chamber.  There is a poorly "
            "made sconce hammered into the wall.");
   SetItems( ([
     "water" :
       "There is water seeping in from both sides.",
     ({"poorly made sconce", "empty sconce", "sconce", "wall"}) :
       "There is a poorly made and empty sconce on the wall.",
     ({"passage", "tunnel", "sides", "side"}) :
       "This passage leads north and east.  It is of a roughly hewn, damp "
       "grey stone.",
     ({"relatively dry chamber", "dry chamber", "chamber"}) :
       "There is a relatively dry chamber off to the north.",
    ({"grey rock", "grey stone", "rock", "chiseled stone", "stone",
      "soft rock", "soft sedimentary rock", "sedimentary rock"}) :
       "This is a soft sedimentary rock that is easy worn by water "
       "or chisel.",
    ({"small footprint", "footprints", "footprint", "small footprints"}) :
      "There are several small footprints heading north.",
           ]) );
    SetListen( ([
      "default" :
        "There are some voices speaking gobyshkin coming from the north.  The "
        "frequent drip of water can be heard.",
             ]) );
    SetSmell( ([
      "default" :
        "The air is fairly moist here, there is a faint smell of burning "
        "herbs coming from the north.",
            ]) );
    SetExits( ([
      "north" : CAVES_ROOM + "cavecc.c",
      "west"  : CAVES_ROOM + "cavet1a",
            ]) );
    SetInventory( ([
      CAVES_NPC + "ggoblin" : 4,
                ]) );
}
