// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("a tunnel intersection.");
   SetLong("Tunnels connect here from four directions: upward, to the "
           "northeast, to the southwest, and to the east.  Water dripping "
           "from the ceiling of this cave has made a small pool in the "
           "center of the room.");
   SetItems( ([
                ({ "cave tunnels","tunnels" }) :
                   "There are four tunnels here, going to the northeast, "
                   "southwest, east, and upward.",
                ({ "northeast tunnel","tunnel" }) :
                   "Small animal footprints line the northeast tunnel.",
                ({ "small animal footprints","small animal footprint",
                   "animal footprints","animal footprint",
                   "footprint","footprints",
                   "small footprint","small footprints" }) :
                   "Little rodents must have passed through to make these "
                   "footprints.",
                ({ "southwest tunnel","tunnel" }) :
                   "The rock looks more damp towards the southwest tunnel.",
                ({ "damp rock","rock" }) :
                   "Damp rock looks darker than rock which is dry.",
                ({ "upward tunnel","tunnel" }) :
                   "The world gets a bit brighter in the upward tunnel.",
                ({ "brighter world","world" }) :
                   "The world brightens in the upward tunnel.",
                ({ "east tunnel","tunnel" }) :
                   "The land seems to be more dry and dusty to the east.",
                ({ "east land","land" }) :
                   "The land turns dry and dusty in the east tunnel.",
                ({ "dripping water","water" }) :
                   "Clear blue water drips from the ceiling.",
                ({ "cave ceiling","ceiling" }) :
                   "The ceiling is wet and dark.",
                ({ "this cave","cave","room" }) :
                    "Clear water has formed a dark pool in the center of "
                    "this room, and four tunnels enter it.",
                ({ "small pool","dark pool","pool" }) :
                   "Clear blue water from the ceiling has formed this small "
                   "pool.",
                ({ "center of room","center" }) :
                   "A small pool of water has formed in the center of the "
                   "room.",
                ({ "water drip","drip" }) :
                   "Dripping water has formed a small pool in the center "
                   "of the room.",
           ]) );
   SetListen( ([
                 "default" : "Sounds coming from the northeast sound "
                    "like small animals.",
            ]) );
   SetSmell( ([
                "default" : "Damp smells of fish come from the southwest."
           ]) );
   SetExits( ([
                "up" : C_ROOM + "rooma",
                "northeast" : C_ROOM + "roomd",
                "east" : C_ROOM + "roomf",
                "southwest" : C_ROOM + "roomh",
           ]) );
   SetInventory( ([
                    C_NPC + "spider" : 3,
               ]) );
}
