#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("on a path");
   
   SetLong("The path of trampled dirt ends here, stopping before a "
           "stone wall; a gate leads through it.  Trees flourish in the "
           "surrounding area, not leaving enough room to move between "
           "then.  The path moves through it to the southwest, "
           "cutting around trees instead of plowing through them all.  "
           "It goes under some wooden platforms.");
   SetItems( ([
                ({ "dirt path","path" }) :
                   (: GetLong :),
                ({ "trampled dirt","dirt" }) :
                   "The dirt is compacted down, but some footprints "
                   "can still be picked out of it.",
                ({ "various footprints","footprints","footprint",
                   "print","prints" }) :
                   "Towards the edge of the path, some footprints "
                   "of various types can be viewed.",
                ({ "stone wall","wall","stone","gray wall","grey wall" }) :
                   "The stone wall surrounds some area to the east of "
                   "here.  A gate is in the middle of it, leading "
                   "inside the grey wall.",
                ({ "deciduous trees","deciduous tree","trees","tree" }) :
                   "The trees clutter in groups and try to block "
                   "movement in all directions.  The path makes it " 
                   "around them and heads off to the southeast.  "
                   "They shake some in the wind.",
                ({ "wooden platforms","wooden platform",
                   "platforms","platform","wood" }) :
                   "Barely visible through the trees are some wooden "
                   "platforms that are clustered together.",
           ]) );
   SetListen( ([
                 "default" : "The trees make noise in the wind.",
            ]) );
   SetExits( ([
                "east" : M_ROOM + "garden_a",
                "southwest" : M_ROOM + "ground_c",
           ]) );
   SetDoor("east",M_ROOM + "gate");
   SetInventory( ([
                    M_NPC + "monk_h" : 2,
                    M_NPC + "monk_c" : 4+random(2),
                    M_NPC + "monk_j" : 1,
               ]) );
}