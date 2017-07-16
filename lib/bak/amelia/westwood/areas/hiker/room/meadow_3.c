#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("in a meadow");
   SetDomain("WestWood");
   SetLong("The ground is soft and slightly squishy, but grass "
           "grows everywhere, carpeting the ground thickly.  "
           "Flowers are scattered about the meadow, showing up here "
           "and there with great variety.  A trail seems to be formed "
           "to the east, and the meadow continues to the north.  The "
           "West Wood blocks movement to the west and south.");
   SetItems( ([
                ({ "west wood","wood","woods","tree","trees" }) :
                   "Trees grow tall and strong to the west and south, "
                   "displaying the true nature of the West Wood.  "
                   "Some trees grow in the meadow, but they are young "
                   "not well rooted.",
                ({ "grassy meadow","meadow" }) :
                   (: GetLong :),
                ({ "narrow trail","trail" }) :
                   "The trail is off to the east.  It appears to "
                   "go in a north-south direction.",
                ({ "thick grass","grass","ground","soft ground",
                   "damp ground","grass carpet","carpet","earth" }) :
                   "The grass grows very thickly over the soft "
                   "and damp ground.  Poking out from the grass "
                   "carpet are wildflowers.",
                ({ "various wildflowers",
                   "wildflowers","flower","flowers",
                   "wildflower" }) :
                   "Many different types of wildflowers grow "
                   "in the meadow.  Most remain near the ground and "
                   "are small in size.",
           ]) );
   SetItemAdjectives( ([
                         "ground" : ({ "soft","squishy" }),
                         "flower" : ({ "small","wild","various" }),
                    ]) );
   SetListen( ([
                 "default" : "The trees clack against each other in the "
                    "wind.",
            ]) );
   SetSmell( ([
                "default" : "The earth smells moist and fresh.",
           ]) );
   SetExits( ([
                "north" : H_ROOM + "meadow_2",
                "east"  : H_ROOM + "trail_07",
           ]) );
   SetInventory( ([
                    H_NPC + "pickboy" : 1,
                    H_NPC + "hiker" : random(2),
               ]) );
}
