#include <lib.h>
#include "../caves.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetAmbientLight(25);
    SetClimate("underground");
    SetShort("the chief's chamber");
    SetLong("This is a thirty by thirty room with relatively smooth walls, "
            "there are "
            "odd paintings over them.  This room is lit somewhat well due "
            "to the firepit in the middle, it is also dry.  There is a "
            "crudely constructed bed by the wall.  The "
            "chamber is of a soft grey stone, with a long passage leading "
            "off "
            "to the south and another chamber to the east.");
    SetItems( ([
      ({"room", "walls", "chamber", "wall"}) :
        "This room has smoothly cut walls compared to the rest of the cave.",
      ({"dry", "dry chamber"}) :
        "This room is dry compared to the rest of the cave.",
      ({"another chamber", "chamber"}) :
        "There is a large wet chamber to the east.",
      ({"firepit", "fire", "middle"}) :
        "The fire provides some light and heat for the room.",
      ({"passage", "long passage"}) :
        "The south leads off to a long passage",
      ({"bedding", "bed"}) :
        "There is a crudely constructed bed here.",
      ({"paintings", "odd paintings", "painting"}) :
        "The paintings in this room are many, and are of a brutal, "
        "animalistic nature.",
     ({"soft grey stone", "grey stone", "stone"}) :
       "This is a soft grey stone easily worn by water or chisel.",
            ]) );
    SetListen( ([
      "default" :
        "There constant pop of the fire can be heard.  The frequent "
        "drip of water can be heard to the south and east.",
            ]) );
    SetSmell( ([
      "default" :
        "The smell of burnt herbs fills the room.",
            ]) );
    SetExits( ([
      "east" : CAVES_ROOM + "caveboul",
      "south" : CAVES_ROOM + "cavet2",
            ]) );
    SetInventory( ([
      CAVES_NPC + "chiefg"   : 1,
      CAVES_NPC + "ggoblin"  : 2,
      CAVES_NPC + "gshaman"  : 1,
                ]) );
}
