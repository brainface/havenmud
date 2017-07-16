// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetShort("the edge of the lake");
   SetLong("The waterfall crashes against the lake here, and one gets "
           "quite a drenching from standing around for a long time.  "
           "Many fish swim around the lake, and there is a path heading "
           "to the southwest, around the lake.  Other exits head up the "
           "cliff to the northwest, and one could climb up also, "
           "following the waterfall.");
   SetItems( ([
                ({ "crashing waterfall","waterfall" }) :
       "The waterfall crashes into the lake.  The wall behind the "
         "waterfall seems to fall away to nothingness.",
                ({ "shallow lake","lake" }) :
                   "Lake fish jump and dive throughout the shallow "
                   "and rather small lake.",
                ({ "lake fish","fish" }) :
                   "The fish are blind, but seem to find their "
                   "way nicely.",
                ({ "southwest path","path" }) :
                   "A dark cave conceals the southwest path.",
                ({ "northwest cliff","cliff" }) :
                   "The cliff isn't very steep, and one could "
                   "climb it to the northwest.",
                ({ "dark cave","cave" }) :
                   "The southwest path leads into a dark cave.",
           ]) );
   SetInventory( ([
                    C_NPC + "dogfish" : 1,
                    C_NPC + "trout" : 3,
                    C_NPC + "catfish" : 1,
               ]) );
  SetEnters( ([
    "waterfall" : "/domains/estergrym/areas/obsidian/start",
    ]) );
   SetExits( ([
                "up" : C_ROOM + "rooms",
                "northwest" : C_ROOM + "roomr",
                "southwest" : C_ROOM + "roomu",
           ]) );
}
