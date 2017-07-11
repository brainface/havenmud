#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetAmbientLight(15);
    SetClimate("underground");
    SetShort("away from cave entrance");
    SetLong("This passage leads away from the cave entrance, shortly "
            "thereafter becoming a tunnel. The moss quickly thins "
            "out, with little light for it.  There tunnel as it is "
            "best described head east, then opens up into a "
            "chamber to the northeast.  This tunnel is about ten "
            "feet across and is composed of the same grey rock as "
            "the entrance.");
   SetItems( ([
     ({"cave", "entrance", "cave entrance"}) :
       "The cave entrance is to the west.",
     "moss" :
       "The moss dies off quuickly due to the lack of enough light.",
     ({"passage", "tunnel"}) :
       "The tunnel leads off to the east, then the northeast. "
       "It is of a roughly hewn, damp grey stone.",
     ({"little light", "light"}) :
       "It's quite dim here, the only light coming from the cave "
       "entrance.",
     "chamber" :
       "This is a roughly hewn chamber about sixty five feet by sixty "
       "five feet to "
       "the northeast.",
    ({"grey rock", "grey stone", "rock", "stone", "sedimentary rock"}) :
       "This is a soft sedimentary rock that is easy worn by water "
       "or chisel.",
           ]) );
    SetListen( ([
      "default" :
        "There are some voices speaking gobyshkin coming from the east and from "
        "the south. The frequent drip of water can be heard. ",
             ]) );
    SetSmell( ([
      "default" :
        "The air is fairly moist here, there is a foul "
        "odor coming from the west.",
            ]) );
    SetExits( ([
      "west"  : CAVES_ROOM + "cavee",
      "northeast" : CAVES_ROOM + "cavemc3",
            ]) );
}
