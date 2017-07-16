#include <lib.h>
#include "../jidnewbi.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("inside a valley");
   SetDomain("Valley");
   SetLong("The cliff walls curve here, going straight off in the "
           "south, but bending slightly to the east in the north.  "
           "The trees allow travel to the north, east, and south, "
           "but the cliff blocks off all other travel.  A few trees "
           "grow on the cliff here, which grows less steep "
           "to the north.");
   SetItems( ([
                ({ "cliff valley","valley","cliff","cliff walls",
                   "cliff wall","wall","walls" }) :
                   (: GetLong :),
                ({ "hardy trees","hardy tree","tree","trees" }) :
                   "The trees grow all over this region, but "
                   "most are in the valley.  A few have begun to "
                   "populate the cliff, as it rises with a less "
                   "steep incline to the north.  The ones on the cliff "
                   "bend out at funny angles, realizing that their "
                   "choice of a growing spot was not necessarily the "
                   "most desirable.  Some of their roots stick out of " 
                   "the cliff.  To the north, the cliff looks more "
                   "rocky than around here.",
                ({ "tree roots","tree root","root","roots" }) :
                   "The roots poke out of the cliff where they have "
                   "lost their fragile hold on the cliff.",
           ]) );
   SetObviousExits("northeast, east, south");
   SetExits( ([
                "northeast" : JD_ROOM + "/canyon_1",
                "east"      : JD_ROOM + "/valley_7",
                "south"     : JD_ROOM + "/valley_4",
           ]) );
   SetInventory( ([
                    JD_NPC + "/centipede" : 2,
                    JD_NPC + "/spider_black" : 1,
                    JD_NPC + "/snake_green" : 1,
               ]) );
}
