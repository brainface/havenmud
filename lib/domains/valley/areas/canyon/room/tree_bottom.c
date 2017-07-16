#include <lib.h>
#include "../jidnewbi.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("on a ledge");
   SetDomain("Valley");
   SetLong("Green, growing things flourish up here on the ledge, "
           "about half-way to the top of the cliff.  It extends back "
           "to the east, where more things grow and a gentle "
           "slope leads off the ledge.  A large tree grows here "
           "among the other plants.");
   SetItems( ([
                ({ "cliff ledge","ledge","cliff","slope" }) :
                   (: GetLong :),
                ({ "green growing things","green growing thing",
                   "green growing plants","green growing plant",
                   "green things","green thing","growing thing",
                   "green plants","green plant","growing plant",
                   "growing things","things","thing",
                   "growing plants","plants","plant" }) :
                   "The principle plant is the large tree that grows "
                   "in the center of them all.",
           ]) );
   SetObviousExits("east");
   SetExits( ([
                "east" : JD_ROOM + "/cliff_other_top",
           ]) );
   SetInventory( ([
                    JD_ROOM + "/climb_up_tree" : 1,
                    JD_NPC + "/chameleon" : 1,
               ]) );
}


/* Approved by Zaxan on Sat Jan 17 03:24:58 1998. */
