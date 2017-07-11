#include <lib.h>
#include "parva.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Parva");
   SetDomain("HavenWood");
   SetClimate("indoors");
   SetAmbientLight(40);
   SetShort("the healer's home");
   SetLong("Curtains hang in the windows and in front of the "
           "open doorway.  A few chairs are scattered around "
           "the colorful rug that is lain out on the floor.  "
           "One can leave by going out.");
   SetItems( ([
                ({ "healer home","home","house" }) :
                   (: GetLong :),
                ({ "window curtains","curtains","curtain","window",
                   "windows","doorway","door" }) :
                   "The curtains are a colorful array of different "
                   "designs and patterns, similar to the rug.  "
                   "They hang in front of the few windows of the "
                   "house, and the doorway.",
                ({ "scattered chairs","chair","chairs" }) :
                   "The chairs are haphazardly placed around the "
                   "room on the rug.  They are painted in gleeful "
                   "colors.",
                ({ "colorful rug","rug","floor" }) :
                   "In any other house, the rug would stand out for "
                   "its wild splash of colors.  Here, it blends in "
                   "and appears almost dull, due to the slightly "
                   "worn feel of it, as compared to the curtains and "
                   "chairs.",
           ]) );
   SetListen( ([
                 "default" : "The shuffling and bustling in the "
                    "streets makes it through the walls.",
            ]) );
   SetSmell( ([
                "default" : "Sweet smells fill the room.",
           ]) );
   SetExits( ([
                "out" : P_ROOM + "/path5",
           ]) );
   SetInventory( ([
                    P_NPC + "/healer" : 1,
                    P_NPC + "/bard" : 1,
               ]) );
}
