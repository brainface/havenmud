// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "balz.h"

static void create() {
   room::create();
   SetShort("a dark forest");
   SetDomain("WestWood");
   SetLong("The entire forest shivers and moves slightly around here, "
           "as if a wind was shaking the branches, but there is not a "
           "wind to be felt.  Trees loom over this small clear spot, "
           "blocking out much light.  Large roots cover the ground, "
           "hiding it from sight.  Small gaps in the trees are "
           "to the northwest, west, and southwest.");
   SetItems( ([
                ({ "large branches","branches","branch" }) :
                   "Great branches interwine above, blocking "
                   "the entrance of light.  They seem to be alive, "
                   "shaking and moving without the wind.",
                ({ "looming trees","trees","tree","looming tree" }) :
                   "Branches come out of the trees from all sides and "
                   "all heights, creating an enclosed atmosphere.",
                ({ "large roots","roots","root","large root" }) :
                   "The large tree roots move little, compared to the "
                   "branches, but some slide about restlessly.",
                ({ "small gaps","gaps","gap" }) :
                   "Small gaps appear in the walls created by the "
                   "tree branches to the west, northwest, and southwest.",
                ({ "small clear spot","small spot","clear spot","spot" }) :
                   (: GetLong :),
           ]) );
   SetExits( ([
                "northwest" : B_ROOM + "/ete",
                "west" : B_ROOM + "/etb",
                "southwest" : B_ROOM + "/eta",
           ]) );
   SetObviousExits("northwest, west, southwest");
   SetInventory( ([
                    B_NPC + "/treea" : random(3)+1,
                    B_NPC + "/treeb" : random(2)+2,
               ]) );
}
