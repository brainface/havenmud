#include <lib.h>
#include "../jidnewbi.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("on a limb");
   SetDomain("Valley");
   SetLong("The thick branch wobbles some, showing how it is "
           "slightly unsafe, but seems mostly solid.  Many small "
           "branches come off the side of this larger branch, and "
           "are all covered with leaves.  The branch leads back to "
           "the main trunk to the north.");
   SetItems( ([
                ({ "thick branch","branch","limb","larger branch" }) :
                   (: GetLong :),
                ({ "small branches","small branch","branch","branches",
                   "leaves","leaf" }) :
                   "Leaves cover the small branches, and all are "
                   "connected back to the main, large branch.  "
                   "The leaves all look healthy.",
                ({ "main trunk","trunk" }) :
                   "The main trunk is to the north.  It is very "
                   "similar to the branch here.",
           ]) );
   SetObviousExits("north");
   SetExits( ([
                "north" : JD_ROOM + "/tree_top",
           ]) );
   SetInventory( ([
                    JD_NPC + "/dryad" : 1,
               ]) );
}



/* Approved by Zaxan on Sat Jan 17 03:24:22 1998. */
