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
            "out, with little light for it to grow.  The tunnel as it is "
            "best decribed heads north, then opens up into a "
            "chamber to the northwest.  This tunnel is about ten "
            "feet across and is composed of the same grey rock as "
            "the entrance.");
   SetItems( ([
     ({"cave", "entrance"}) :
       "The entrance is to the south.",
     ({"passage", "tunnel"}) :
       "The tunnel leads off to the north, then the northwest "
       "It is of a roughly hewn, damp grey stone.",
     ({"little light", "light"}) :
       "It's quite dim here, the only light coming from the cave "
       "entrance.",
     "chamber" :
       "This is a roughly hewn chamber about thirty feet by thirty feet to "
       "the northwest.",
    ({"grey rock", "grey stone", "rock", "soft sedimentary rock", 
      "rock", "stone", "grey stone", "damp grey stone"}) :
       "This is a soft sedimentary rock that is easy worn by water "
       "or chisel.",
      "moss" :
        "The moss dies off here do to lack of light.",
           ]) );
    SetListen( ([
      "default" :
        "There are some voices speaking gobyshkin coming from the south. "
        " The frequent drip of water can be heard.",
             ]) );
    SetSmell( ([
      "default" :
        "The air is fairly moist here, there is a foul odor coming "
        "from the south.",
            ]) );
    SetExits( ([
      "south" : CAVES_ROOM + "cavee",
      "northwest" : CAVES_ROOM + "cavemush",
            ]) );
}
