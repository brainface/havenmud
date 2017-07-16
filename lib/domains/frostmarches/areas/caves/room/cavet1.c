#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetAmbientLight(5);
    SetClimate("underground");
    SetShort("a passage");
    SetLong("This passage leads east and west.  It is somewhat wet, "
            "with water seeping in from both sides.  The passage is "
            "about ten feet across, and is composed of a roughly chiseled "
            "stone.  There are some small footprints heading east.  "
            "The tunnel slopes downward slightly and has a slight "
            "twist to it.  It appears to be chiseled out with crude "
            "tools.");
   SetItems( ([
     ({"water", "water seeping"}) :
       "There is water seeping in from both walls.",
     ({"twist", "slope", "slopes"}) :
       (: GetLong :),
     ({"passage", "tunnel", "sides", "side"}) :
       "This passage leads east and west. It is of a roughly hewn, damp "
       "grey stone.",
     ({"T", "T intersection", "intersection"}) :
       "There is a T intersection off to the west.",
    ({"grey rock", "grey stone", "rock", "chiseled stone", "stone"}) :
       "This is a soft sedimentary rock that is easy worn by water "
       "or chisel.",
   ({"footprint", "small footprint", "footprints", "small footprints"}) :
     "There are small footprints heading east here.",
           ]) );
    SetListen( ([
      "default" :
        "There are some voices speaking gobyshkin coming from the east.  The "
        "frequent drip of water can be heard.",
             ]) );
    SetSmell( ([
      "default" :
        "The air is fairly moist here, there is an ogrish stench coming "
        "from the west.",
            ]) );
    SetExits( ([
      "east"  : CAVES_ROOM + "cavet1a",
      "west"  : CAVES_ROOM + "cavet",
            ]) );
}
