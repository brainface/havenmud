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
            "about ten feet across, and is composed of roughly chiseled "
            "stone.  There are some small footprints heading east.  "
            "The passage has a slight twist to it, and appears to "
            "have been made with some dull chisel.");
   SetItems( ([
     "water" :
       "There is water seeping in from both sides.",
     ({"passage", "tunnel", "side", "sides"}) :
       "This passage leads east and west. It is of a roughly hewn, damp "
       "grey stone.",
      ({"twist", "slight twist", "dull chisel"}) :
        (: GetLong :),
      ({"rock", "stone", "grey stone", "chiseled stone"}) :
       "This is soft sedimentary rock that is easily worn by water "
       "or chisel.",
     ({"footprint", "footprints", "small footprints", "small footprint"}) :
       "There are small footprints heading east.",
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
      "east"  : CAVES_ROOM + "cavet2",
      "west"  : CAVES_ROOM + "cavet1.c",
            ]) );
}
