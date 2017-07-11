#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("the donjon entryway");
   SetLong("Stones of a generally uniform size make up the walls of the "
           "donjon, the main building on the castle.  Roughly squared "
           "wooden beams help support the sheer weight of the rocks.  "
           "To the west, the room continues on, but to the east are "
           "two large doors that lead out of the castle.  To the south, "
           "an open archway leads to a small room.");
   SetItems( ([
                ({ "open archway","archway","arch","open arch",
                   "small room","room" }) :
                   "To the south, one can go to a small room through "
                   "an opening in the shape of an arch.  Its design "
                   "allows the weight of the rocks about to hold it "
                   "together even more solidly.",
                ({ "donjon walls","donjon wall","walls","wall",
                   "stones","stone","uniform stones","uniform stone",
                   "rocks","rock","roughly squared wooden beams",
                   "roughly squared beams","squared beams",
                   "squared wooden beams","wooden beams","beams",
                   "beam","roughly squared wooden beam","squared beam",
                   "roughly squared beam","squared wooden beam",
                   "wooden beam" }) :
                   "The walls are made up of uniform stones that are "
                   "the same general shape, color, and size.  Wooden "
                   "beams help to support the weight of all those "
                   "rocks.",
                ({ "donjon entryway","entryway","entry","donjon",
                   "castle","main building","building","room" }) :
                   (: GetLong :),
           ]) );
   SetExits( ([
                "east"  : VC_ROOM + "/gen_07",
                "west"  : VC_ROOM + "/hall1",
                "south" : VC_ROOM + "/stair1",
           ]) );
   SetInventory( ([
                    VC_NPC + "/servant" : 1,
               ]) );
}
