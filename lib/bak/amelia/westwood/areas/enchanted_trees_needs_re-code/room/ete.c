// Amelia@Haven

#include <lib.h>
inherit LIB_FISHING;
#include "balz.h"

static void create() {
   fishing::create();
   SetShort("a small pool");
   SetDomain("WestWood");
   SetLong("The trees above spread apart here, letting light seep through "
           "and hit a small pool here.  A little stream runs through "
           "the trees, stirring up the pool some so it doesn't become "
           "stagnant.  More gaps appear in the trees to walk through "
           "to the southeast, south, southwest, and west.");
   SetItems( ([
                ({ "large trees","trees","tree","large tree" }) :
                   "The trees densely fill all the area around here, but "
                   "have left a gap straight above, allowing the pool "
                   "to be healthy and clean.",
                ({ "small pool","pool" }) :
                   "Shapes move around in the small pool, which is fed "
                   "and empty by a little stream.",
                ({ "little stream","stream" }) :
                   "The little stream tinkles along quietly.",
                ({ "moving shapes","shapes","shape" }) :
                   "Small shapes like fish move around in the pool.",
                ({ "small gaps","gaps","gap" }) :
                   "Gaps in the trees appear to the southeast, south, "
                   "southwest, and west for one to move through.",
           ]) );
   SetExits( ([
                "west" : B_ROOM + "/etd",
                "south" : B_ROOM + "/eta",
                "southwest" : B_ROOM + "/etb",
                "southeast" : B_ROOM + "/etc",
           ]) );
   SetObviousExits("west, south, southwest, southeast");
   SetSpeed(5);
   SetFish( ([ B_NPC + "/fish" : 90 ]) );
   SetChance(25);
   SetMaxFishing(12);
   SetInventory( ([
                    B_NPC + "/treea" : random(3)+1,
               ]) );
}
