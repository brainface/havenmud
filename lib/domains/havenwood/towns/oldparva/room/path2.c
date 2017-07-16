#include <lib.h>
#include "parva.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Parva");
   SetShort("in Parva");
   SetDomain("HavenWood");
   SetLong("Parva is a town of dust and dirt and ramshackle buildings "
           "near the coast.  There is a shack to north side of the path "
           "at this point; the path goes off to the west and east.  "
           "Another path wanders off to the south from here.  "
           "The Havenwood grows in the distance to the south, "
           "but before the growing trees are the rotting stumps "
           "that used to be trees.");
   SetItems( ([
                ({ "Parva","parva","town" }) :
                   (: GetLong :),
                ({ "dirty path","path","dust","dirt" }) :
                   "The path is simple dirt; a good deal "
                   "is dry enough to fill the air with "
                   "dust.",
                ({ "ramshackle buildings","buildings","fish store","store","building",
                   "shack","shacks" }) :
                   "The buildings of Parva were built to be "
                   "temporary, but most haven't been upgraded "
                   "since then.  The only one accessable from "
                   "here is on the north side of the path.",
                ({ "rotting stumps","stumps","stump" }) :
                   "The tree stumps rot in the weather, slowing "
                   "turning into fertile dirt for new trees to "
                   "grow in.  The people of Parva cut down many "
                   "trees, leaving the stumps behind, to build "
                   "their ships, houses, and docks.",
                ({ "growing trees","tree","trees","havenwood" }) :
                   "The trees flourish in the climate of the "
                   "Havenwood.  They are all deciduous.",
           ]) );
   SetItemAdjectives( ([
                        "stumps" : ({ "rotting","tree" }),
                        "path" : ({ "dirty","dusty" }),
                        "trees" : ({ "deciduous","growing" }),
                    ]) );
   SetListen( ([
                 "default" : "Waves crash to the east.",
            ]) );
   SetSmell( ([
    "default" : "The reek of fish comes from the building "
    "to the north.",
           ]) );
   SetExits( ([
                "east"  : P_ROOM + "/path3",
                "west"  : P_ROOM + "/path1",
                "south" : P_ROOM + "/cpath",
           ]) );
   SetEnters( ([
                 "building" : P_ROOM + "/fstore",
            ]) );
   SetInventory( ([
                  P_OBJ + "/sign2" : 1,
                   P_OBJ + "/fountain" : 1,
              ]) );
}


/* Approved by Ukla on Mon Oct 19 16:19:19 1998. */
