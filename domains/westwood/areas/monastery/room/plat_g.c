#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("on a platform");
   
   SetLong("The platform here is solid, but it sways on the branches "
           "in the breeze.  A ramp connects it with another platform to "
           "the east, and a ladder goes up into a platform slightly "
           "above, poking its way through a hole in the center.  Many "
           "leaves skitter across the platform and towards the rest of " 
           "the world.");
   SetItems( ([
                ({ "tree branches","tree branch","branches","branch",
                   "long limbs","long limb","limbs","limb" }) :
                   "The branches fill the area with their long limbs, "
                   "supporting the platforms and the ramp.",
                ({ "wooden platforms","platforms","wood","platform",
                   "wooden platform" }) :
                   "The platforms are supported by the many branches "
                   "here, and are stable.  They do move some when the "
                   "wind hits, however.",
                ({ "wooden ramp","ramp","wood","wood ramp" }) :
                   "A ramp meanders off to the east, going through a "
                   "maze of those branches it deams strong enough to "
                   "hold it.  As such, it follows a course that isn't "
                   "straight in the least.",
                ({ "wooden ladder","ladder","wood","wood ladder",
                   "hole" }) :
                   "The wooden ladder goes up through a hole in the "
                   "platform above.  It has been carefully hammered into "
                   "place to prevent the wind from taking it away.",
                ({ "skittering leaves","skittering leaf","leaves",
                   "leaf" }) :
                   "Leaves dash about as a gust of wind hits them, "
                   "running all over and falling into things.",
           ]) );
   SetListen( ([
                 "default" : "A the wind gusts, the branches creak "
                    "and the leaves rustle.",
            ]) );
   SetExits( ([
                "up"   : M_ROOM + "someroom",
                "east" : M_ROOM + "plat_h",
           ]) );
   SetInventory( ([
                    M_NPC + "monk_j" : 2,
                    M_NPC + "monk_h" : 1,
               ]) );
}