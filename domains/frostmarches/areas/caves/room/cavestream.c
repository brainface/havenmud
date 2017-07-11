#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetAmbientLight(3);
    SetClimate("underground");
    SetShort("a wet chamber");
    SetLong("This is a rather wet twenty by twenty chamber.  It is composed "
            "of a "
            "grey sedimentary rock.  Water drips down the room's "
            "ceiling and soaks through it's walls.  Due to this the "
            "room looks somewhat unstable and prone to collapse.  There "
            "is a little rubble on the floor.  A passage leads northwest "
            "back to a main chamber.  It appears this room hasn't been "
            "worked on for quite some time.");
    SetItems( ([
      ({"rock", "grey rock", "stone"}) :
        "This is a soft stone easily worn by water or chisel.",
      ({"chamber", "room"}) :
        "This room looks somewhat deteriated due to the water seeping through "
        "the walls.",
      ({"passage", "main chamber"}) :
        "A small passage leads northwest back to the main common chamber.",
      ({"wet", "water", "walls", "ceiling", "wall"}) :
        "There is water continually seeping through the walls and ceiling "
        "only to dissapear again into the floor.",
      ({"rubble", "unstable", "collapse"}) :
        "There is some rubble on the floor due deteriation by the water.",
      ({"floor", "hole", "small hole"}) :
        "The water is draining into a small hole in the floor.",
           ]) );
    SetListen( ([
      "default" :
        "The constant drip of water can be heard all arond you.",
             ]) );
    SetSmell( ([
      "default" :
      "The air in here is very damp.  A slight smell of rubbish comes "
      "off from the northwest.",
            ]) );
    SetExits( ([
      "northwest" : CAVES_ROOM + "cavemc4",
            ]) );
    SetInventory( ([
      CAVES_OBJ + "spring" : 1,
                ]) );
}
