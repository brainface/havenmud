#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("beneath the waterfall");
   SetLong("Water tumbles over piles of dark rock, filling a nice "
           "shallow lake below.  Occasionally, a wriggling shape drops "
           "over the edge of the waterfall and disappears in the spray.  "
           "There is a ledge to the west that can be easily reached, and "
           "one could continue climbing down the rocks to the lake, as "
           "well.");
   SetItems( ([ 
                ({ "tumbling water","water" }) :
                   "The water tumbles down to the lake below.",
                ({ "dark rocks","rock","rocks","dark rock" }) :
                   "The rock is dark, and wet.",
                ({ "shallow lake","lake" }) :
                   "The lake below is shallow, and many fish seem "
                   "to be swimming around in it.",
                ({ "falling fish","fish" }) :
                   "The fish coming down the waterfall come too "
                   "quickly to follow, and the ones below in the lake are "
                   "too far away.",
                ({ "wriggling shape","shape" }) :
                   "The shapes falling down the waterfall are "
                   "probably fish.",
                ({ "tumbling waterfall","waterfall" }) :
                   "The waterfall is not very large.",
                ({ "spraying water","spray" }) :
                   "The water splashes up when it hits the rocks, "
                   "and when it enters the lake below.",
                ({ "western ledge","ledge" }) :
                   "There is a comfortable looking ledge to the "
                   "west.",
           ]) );
   SetInventory( ([
                    C_NPC + "smouse" : 1,
               ]) );
   SetExits( ([ "west" : C_ROOM + "roomr",
                "up" : C_ROOM + "roomo",
                "down" : C_ROOM + "roomt" ]) );
}
