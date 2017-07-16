#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

int PreExit();

static void create() {
   room::create();
   SetDomain("WestWood");
   SetShort("under a platform");
   SetLong("Tree trunks, long dead but not yet decayed, are set in "
           "place to hold up a wooden platform that is above.  "
           "No access exists here, but a path goes south and east through "
           "this area.  The soft dirt shows many footprints going along "
           "the path, but travel can be made to the north and west "
           "also.");
   SetItems( ([
                ({ "dirt path","path","soft dirt","dirt" }) :
                   "Footprints of various shapes and sizes cover the "
                   "dirt path, and in its soft dirt grow a few small "
                   "plant sprouts.  The path goes east and south; "
                   "continuing other the platform to the east but "
                   "going into the open air to the south.",
                ({ "footprints in the dirt","footprint in the dirt",
                   "footprints in dirt","footprint in dirt",
                   "footprints","footprint","prints","print" }) :
                   "The path has many footprints on it; most seem "
                   "to belong to muezzin.  However, a few prints from "
                   "almost all the other races can be picked out "
                   "as well.",
                ({ "small plant sprouts","little plants","little plant",
                   "plant","plants","small plant sprout","plant sprout",
                   "plant sprouts","sprout","sprouts" }) :
                   "Little plants stick out of the ground, but "
                   "will probably be pulled out shortly to keep the "
                   "path free.",
                ({ "tree trunks","tree trunk","trunks","trunk" }) :
                   "The tree trunks have been chopped off so they "
                   "can support the platform from beneath, instead "
                   "of employing other parts of the tree, or attaching "
                   "it half onto the trunk.",
                ({ "wooden platform","platform" }) :
                   "The underside of the platform is probably not "
                   "nearly as interesting as the top.  It has been "
                   "cleaned from any mosses that may have started "
                   "to grow on it in the past, and looks strong.",
           ]) );
   SetListen( ([
                 "default" : "Rambuncious noises come from the "
                    "other side of the platform.",
            ]) );
   SetSmell( ([
                "default" : "The dank smells of the earth fill the "
                   "air.",
           ]) );
   SetExits( ([
                "east"  : M_ROOM + "ground_f",
                "south" : M_ROOM + "ent",
           ]) );
   AddExit("north",M_ROOM + "ground_b",(: PreExit :) );
   AddExit("west",M_ROOM + "ground_d",(: PreExit :) );
   SetInventory( ([
                    M_NPC + "monk_j" : 1,
                    M_NPC + "monk_h" : 1,
                    M_NPC + "trav_wor" : 2,
               ]) );
}

int PreExit() {
   if(this_player()->GetProperty("monasterynoleave")) return 0;

   return 1;
}