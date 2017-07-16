// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "balz.h"

static void create() {
   room::create();
   SetShort("before a hut");
   SetDomain("WestWood");
   SetLong("The trees have created a cavern-like area where a hut "
           "resides.  Above, great branches form a block against the "
           "light and to all sides, as well.  Small gaps appear in this "
           "wall to the east, and to the southeast.");
   SetItems( ([
                ({ "large trees","trees","tree" }) :
                   "Huge trees arch above the hut here, and huge "
                   "branches poke out of them in all directions and "
                   "at all heights, forming a wall to all sides with "
                   "two gaps.",
                ({ "run-down hut","hut" }) :
                   "Some strange material forms this hut, something "
                   "not metal and not wood.  The trees seem to "
                   "very protective of it, however.",
                ({ "great branches","branches","branch","huge branches" }) :
                   "The branches arch above and block out the light, "
                   "hiding the hut from the outside world.",
                ({ "small gaps","gaps","gap" }) :
                   "Small gaps appear in the branches and trees to "
                   "the east and southeast.",
           ]) );
   SetExits( ([
                "east" : B_ROOM + "/ete",
                "southeast" : B_ROOM + "/etb",
           ]) );
   SetEnters( ([
                 "hut" : B_ROOM + "/hut",
            ]) );
   SetObviousExits("east, southeast, enter hut");
   SetInventory( ([
                    B_NPC + "/treeb" : random(5)+2,
               ]) );
}
