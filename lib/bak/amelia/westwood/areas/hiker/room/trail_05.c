#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("on a trail");
   SetDomain("WestWood");
   SetLong("Signs that a stream once ran under these planks are evident "
           "in the lack of grass in one strip, and the rockiness of the "
           "ground there.  The planks of wood turn towards the northwest "
           "from the west here, a steep turn that has made the planks "
           "suddenly shorten to make it effectively.  The ground gets "
           "a little steeper, but not much else changes.");
   SetItems( ([
                ({ "narrow trail","trail" }) :
                   (: GetLong :),
                ({ "stream signs","sign","signs",
                   "stream","ground","strip","run-off" }) :
                   "The stream may have been just a small run-off caused by "
                   "a sudden excess of rain, nothing large, but it "
                   "appears to have cleared enough space to walk south.  "
                   "The dirt has been washed away from much of the "
                   "strip, leaving the ground rocky.",
                ({ "wooden planks","plank","planks","wood","board",
                   "boards" }) :
                   "The planks make a sudden turn from west to northwest. "
                   "Because it is so sharp a curve, the planks shrink "
                   "to a short length to make the turn.  They extend to "
                   "the west, however.  They are made of wood and "
                   "appear weathered and old.",
           ]) );
   SetItemAdjectives( ([
                         "ground" : ({ "rocky" }),
                         "signs" : ({ "stream","small" }),
                         "boards" : ({ "board of","plank of","wooden",
                                       "planks of","boards of","wood" }),
                    ]) );
   SetListen( ([
                 "default" : "Something rustles noisily in the south.",
            ]) );
   SetObviousExits("west, northwest");
   SetExits( ([
                "west"      : H_ROOM + "trail_04",
                "northwest" : H_ROOM + "trail_06",
                "south"     : H_ROOM + "shortcut",
           ]) );
   SetInventory( ([
                    H_NPC + "hiker" : 3+random(2),
               ]) );
}
