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
            "best described heads south, then opens up into a "
            "T intersection to the south.  This tunnel is about ten "
            "feet across and is composed of the same grey rock as "
            "the entrance.  The tunnel has a slight upward slope and "
            "it appears a crude chisel was used to make it.");
   SetItems( ([
     ({"Slope"}) :
       (: GetLong :),
     ({"cave", "entrance"}) :
       "The cave entrance is to the north.",
     ({"passage", "tunnel"}) :
       "The tunnel leads off to the south, then the east and "
       "west. It is of a roughly hewn, damp grey stone.",
     ({"moss"}) :
       "The moss quickly dies off here, lacking enough light to grow.",
     ({"little light", "light"}) :
       "It's quite dim here, the only light coming from the cave "
       "entrance.",
     ({"T", "T intersection", "intersection"}) :
       "This is an intersection of roughly hewn, grey stone heading "
       "east and west.",
    ({"grey rock", "grey stone", "rock", "stone", "grey stone"}) :
       "This is a soft sedimentary rock that is easy worn by water "
       "or chisel.",
           ]) );
    SetListen( ([
      "default" :
        "There are some voices speaking gobyshkin coming from the north and from "
        "the south. The frequent drip of water can be heard. ",
             ]) );
    SetSmell( ([
      "default" :
        "The air is fairly moist here, there is a foul "
        "odor coming from the north.",
            ]) );
    SetExits( ([
      "north" : CAVES_ROOM + "cavee",
      "south" : CAVES_ROOM + "cavet",
            ]) );
}
