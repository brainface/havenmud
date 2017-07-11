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
            "out, with little light for it.  The tunnel as it is "
            "best described heads west, then opens up into a "
            "chamber to the south. This tunnel is about ten "
            "feet across and is composed of the same grey rock as "
            "the entrance.  The tunnel slopes downward slighty, and "
            "appears to have been chipped out carelessly.");
   SetItems( ([
     ({"slopes", "slope", "slopes downward", "slopes slightly"}) :
       (: GetLong :),
     "moss" :
       "The moss quickly dies off here.",
     ({"entrance", "cave", "cave entrance"}) :
       "The cave entrance is to the east.",
     ({"passage", "tunnel"}) :
       "The tunnel lead off to the west, then opens up into a "
       "chamber at the south. It is of a roughly hewn, damp "
       "grey stone.",
     ({"little light", "light"}) :
       "It's quite dim here, the only light coming from the cave "
       "entrance.",
     "chamber" :
       "This is a chamber of roughly hewn grey stone.  It is about "
       "twenty feet across by twenty feet deep.",
    ({"grey rock", "grey stone", "rock", "chipped rock", "stone",
      "damp grey stone", "soft grey rock", "sedimentary rock"}) :
       "This is a soft sedimentary rock that is easy worn by water "
       "or chisel.",
           ]) );
    SetListen( ([
      "default" :
        "There are some voices speaking gobyshkin coming from the east. "
        "The frequent drip of water can be heard.",
             ]) );
    SetSmell( ([
      "default" :
        "The air is fairly moist here, there is a foul "
        "odor coming from the south.",
            ]) );
    SetExits( ([
      "east" : CAVES_ROOM + "cavee",
      "south" : CAVES_ROOM + "cavebone",
            ]) );
}
