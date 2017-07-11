#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("on a branch");
   
   SetLong("The branch ends a little ways along, finishing its trek "
           "as it shrinks to smaller and smaller sizes.  It is tangled "
           "with some other nearby branches, but it would be near "
           "impossible to make it over to any of them and continue "
           "moving through the trees.  The branch grows to be more "
           "solid and thick to the northwest, and here it splits into "
           "even smaller branches.");
   SetItems( ([
                ({ "shrinking branch","branch","thick branch" }) :
                   (: GetLong :),
                ({ "nearby branches","nearby branch","branches",
                   "branch" }) :
                   "Nearby are many other branches, but none are close "
                   "enough to get on and few would be thick enough to "
                   "support someone.",
                ({ "forest trees","forest tree","trees","tree",
                   "forest" }) :
                   "The forest is full of many trees, all growing "
                   "thick and strong into the sky above.",
           ]) );
   SetListen( ([
                 "default" : "The wind rustles the branches.",
            ]) );
   SetExits( ([
                "northwest" : M_ROOM + "branch",
           ]) );
   SetInventory( ([
                    M_NPC + "kid" : random(2),
               ]) );
}
