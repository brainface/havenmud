#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetAmbientLight(10);
    SetClimate("underground");
    SetShort("a wet chamber");
    SetLong("This is a thirty by thirty room, with a small passage running "
            "off to "
            "the west.  The entire eastern side of the room is completely "
            "filled with rubble.  Water soaks in from all sides and from "
            "the ceiling.  The floor is relativly clean, with the exception "
            "of the scattered rocks.");
    SetItems( ([
      ({"passage"}) :
        "There is a small passage that leads off to a western room.",
      ({"eastern side", "room", "side rubble", "chamber"}) :
        "The eastern side of the room has completely collapsed and is "
        "totally buried.",
      ({"scattered rocks", "rocks", "rock", "floor rubble"}) :
        "These are some scattered rocks on the floor when the room "
        "collapsed.",
      ({"water", "sides", "ceiling"}) :

        "Water seeps in from all sides of the room.",
      ({"floor", "clean", "rubble"}) :
        "There are small bits of rubble on the rest of the floor from the "
        "collapsed room.",
            ]) );
    SetListen( ([
      "default" :
        "There constant drip of water can be heard.  The pop of fire can "
        "be heard off to the west.",
             ]) );
    SetSmell( ([ 
      "default" :
        "The air is moist here.  The air smells of burning herbs.",
            ]) );
    SetExits( ([
      "west" : CAVES_ROOM + "cavecc",
            ]) );
}
