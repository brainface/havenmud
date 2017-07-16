#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetAmbientLight(5);
    SetClimate("underground");
    SetShort("a chamber with mushrooms.");
    SetLong("This chamber is about thirty feet wide by about thirty feet "
            "across.  It is of the same grey stone as the rest of "
            "the cave.  There are many mushrooms growing here of "
            "all sizes and colors.  The occasional muddy footprints "
            "circle around the room then head out. There is a passage "
            "off to the southeast.  The chamber looks unfinished and "
            "appears to have been left untouched for quite some time.");
    SetItems( ([
      ({"color", "colors"}) :
        "Some of the mushrooms are blue.",
      "passage" :
        "This is a short, small passage that leads back to the entrance.",
      ({"chamber", "cave", "room", "unfinished", "untouched"}) :
        "This chamber is about thirty feet wide by thirty feet across and "
        "is of the same stone type "
        "as the rest of the cave.",
      ({"stone", "grey stone"}) :
        "This is a soft sedimentary stone, easily worn by chisel or "
        "water.",
      ({"mushrooms", "mushroom"}) :
        "These are standardly shaped mushrooms of the non-edible "
        "variety.  Some of them have developed some truly odd "
        "colors.",
      ({"muddy footprints", "footprints", "footprint"}) :
        "There are many muddy footprints circling about the room, most "
        "of which are fairly small.",
            ]) );
    SetSmell( ([
      "default" :
        "This room has an odd mushroomy scent. The air is fairly moist "
        "and there is a foul odor coming from the southwest.",
            ]) );
    SetListen( ([
      "default" :
        "There are voices speaking gobyshkin coming from the southwest.  The "
        "frequent drip of water can be heard.",
             ]) );
    SetExits( ([
      "southeast" : CAVES_ROOM + "caven",
            ]) );
}
