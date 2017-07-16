#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("in a meadow");
   
   SetLong("The meadow is bordered with the deciduous trees of the "
           "West Wood to the east, north, and west, but there is a "
           "trail that exists to the west and north built out of "
           "wooden boards.  To the south and some to the southeast, "
           "as well, the meadow stretches out, "
           "colorful and beautiful.");
   SetItems( ([
                ({ "narrow meadow","meadow" }) :
                   (: GetLong :),
                ({ "west wood","wood","woods","deciduous trees",
                   "deciduous tree","trees","tree","wall","walls" }) :
                   "The trees flourish to the east, north, and west, "
                   "effectively closing off the meadow and stopping its "
                   "forward progress.  They are tall and twist around "
                   "each other, weaving themselves together into "
                   "walls.",
                ({ "narrow trail","trail","boards","board","wooden boards",
                   "wooden board","wood" }) :
                   "The trail starts in the westward view, going off to "
                   "the south and then towards the northeast, where the "
                   "trail turns once again.  From there, it heads "
                   "straight to the north and the boards it is made of "
                   "drop from sight.",
           ]) );
   SetItemAdjectives( ([
                         "meadow" : ({ "narrow","colorful","beautiful" }),
                    ]) );
   SetListen( ([
                 "default" : "All is quiet, save a slight breeze.",
            ]) );
   SetExits( ([
                "north"     : H_ROOM + "trail_11",
                "southeast" : H_ROOM + "meadow_8",
                "west"      : H_ROOM + "trail_10",
                "south"     : H_ROOM + "meadow_5",
           ]) );
   SetInventory( ([
                    H_NPC + "hiker" : 2+random(3),
               ]) );
}
