// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("a stepping stone bridge");
   SetLong("The stream bends over another waterfall here, heading "
           "down into darkness.  Near the peak of the falls, right "
           "before water turns over the edge, there is a bridge of "
           "stepping stones leading across to a ledge that is on "
           "the other side of the river.  Fish swim happily "
           "around in the swift current.");
   SetItems( ([
                ({ "bridged stream","stream","river" }) :
                   "The stream sloshes along towards the falls.",
                ({ "falls","waterfall" }) :
                   "The waterfall noisily runs over the edge.",
                ({ "waterfall's edge","edge","peak" }) :
                   "At the edge of the falls, there is a bridge "
                   "of stepping stones.",
                ({ "stepping stones","stones","stone","stepping stone" }) :
                   "The stones are of large, flat rocks, making "
                   "it fairly easy to cross here.",
                ({ "large flat rock","large rock","flat rock","rock",
                   "large flat rocks","large rocks","flat rocks","rocks" }) :
                   "The rock is fairly dark in color, turning to "
                   "a more pale shade across the river.",
                ({ "stepping stone bridge","bridge" }) :
                   "The stepping stone bridge is at the edge of "
                   "the falls.",
                ({ "happily swimming fish","fish" }) :
                   "The fish swim upstream as fast as they can "
                   "to escape the waterfall's turbulent currents.  Some, "
                   "however, get swept over the edge.",
                ({ "swift currents","currents","current","swift current" }) :
                   "The currents swirl around the rocks.",
           ]) );
   SetListen( ([
                 "default" : "The river noisily rushes towards the "
                    "edge.",
           ]) );
   SetExits( ([
                "north" : C_ROOM + "roomm",
                "up" : C_ROOM + "roomi",
                "down" : C_ROOM + "rooms",
                "west" : C_ROOM + "roomn",
           ]) );
   SetInventory( ([
                    C_NPC + "trout" : 1,
                    C_NPC + "dogfish" : 4,
               ]) );
}
