#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("under a platform");
   SetDomain("WestWood");
   SetLong("A path of packed dirt goes north and west across the ground "
           "here, shaded by the platform above.  Trees, cut and "
           "fashioned into supports, hold up the platform among the many "
           "green plants that grow profously beneath.  Live trees pack "
           "together to the east and south, preventing passage in those "
           "directions.");
   SetItems( ([
                ({ "path of packed dirt","path","packed dirt",
                   "dirt" }) :
                   "The dirt is more trampled here than it seems to be "
                   "to the west; the path thins into a straight, simple "
                   "line going directly from the west to the north.",
                ({ "large wooden platform","large platform",
                   "wooden platform","platform" }) :
                   "Blocking most of the sky from view is a large wooden "
                   "platform.  A number of trees have been turned "
                   "into supports to hold up the platform in its "
                   "place in the air.",
                ({ "support trees","tree","supports","trees",
                   "support","support tree" }) :
                   "Many of the support trees have been cut apart; "
                   "the tops were sliced off and then used to build "
                   "other supports.  The bottom halves were often "
                   "just left as they were in the ground, not yet "
                   "have started to decompose; the platform is balanced "
                   "upon them as well.",
                ({ "green plants","green plant","plant","plants" }) :
                   "The plants tend to grow mostly under the living "
                   "trees, though some have attempted to spread out "
                   "in the dirt under the platform.  Those are just "
                   "barely sticking out of the ground right now.",
                ({ "live tree","live tree","tree","trees","living trees",
                   "living tree","blockade" }) :
                   "The live trees form a blockade that prevents travel "
                   "to the east and south.  Plants grow under and "
                   "among them.",
           ]) );
   SetListen( ([
                 "default" : "Noise floats down from above.",
            ]) );
   SetSmell( ([
                "default" : "Dirt smells raise from the ground.",
           ]) );
   SetExits( ([
                "north" : M_ROOM + "ground_c",
                "west"  : M_ROOM + "ground_e",
           ]) );
   SetInventory( ([
                    M_NPC + "trav_wor" : 1,
                    M_NPC + "monk_j" : 2,
                    M_NPC + "monk_h" : 3,
               ]) );
}