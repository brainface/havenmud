#include <lib.h>
#include "../jidnewbi.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("inside a valley");
   SetDomain("Valley");
   SetLong("Trees flourish in abundance here, leaving room to travel "
           "north, northeast, east, and south.  A path meanders along "
           "to the east and northest, avoiding all possible "
           "obstacles in a search for the path of least resistance.  "
           "To the west is a high cliff, blocking all progress in "
           "that direction.");
   SetItems( ([
                ({ "flourishing trees","flourishing tree","tree",
                   "trees" }) :
                   "The trees stand high and tall, and a path "
                   "wanders between them.  To the north, some appear "
                   "to be growing on the cliff where there is more "
                   "dirt and soil than there is in most parts of the "
                   "cliff.",
                ({ "dirt and soil","dirt","soil" }) :
                   "Some has collected in pockets on the cliff to the "
                   "north, allowing trees to grow there.",
                ({ "meandering path","path" }) :
                   "The path curves around trees to the east and "
                   "northeast, weakly attempting to find a way "
                   "that has no hardships to it.",
                ({ "high cliff","cliff","valley" }) :
                   (: GetLong :),
           ]) );
   SetObviousExits("north, northeast, east, south");
   SetExits( ([
                "northeast" : JD_ROOM + "/valley_7",
                "east"      : JD_ROOM + "/valley_5",
                "north"     : JD_ROOM + "/valley_6",
                "south"     : JD_ROOM + "/valley_1",
           ]) );
   SetInventory( ([
                    JD_NPC + "/mosquito" : 3+random(4),
                    JD_NPC + "/hummingbird" : 1,
               ]) );
}
