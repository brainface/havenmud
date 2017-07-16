#include <lib.h>
inherit LIB_ROOM;
#include "sdm.h"

static void create() {
   room::create();
   SetShort("a large horse stall");
   SetLong("The horse stall is lush, with about four inches of hay "
           "blanketing the floor.  A netted feeding hammock hangs from one "
           "corner filled with a few flakes of hay.  There are also two "
           "buckets, one with water, and one with grain, on the floor.");
   SetItems( ([
                ({ "two buckets","bucket","buckets","water bucket",
                   "grain bucket","grain","water" }) :
                   "Both the grain and the water buckets are around "
                   "half-full of their respective item.",
                ({ "netted feeding hammock","feeding hammock",
                   "netted hammock","hammock","corner" }) :
                   "It is for feeding the horses.  There is some food "
                   "still left in the bottum.  Right now, the hammock "
                   "is in the corner with some of the hay.",
                ({ "large horse stall","large stall","horse stall",
                   "stall","barn" }) :
                   (: GetLong :),
                ({ "four inches of hay","hay","blanketed floor","floor",
                   "flakes of hay","flake","flake of hay" }) :
                   "The hay on the ground is four inches deep, blanketing "
                   "the floor.  A few flakes fill one corner with "
                   "a netted feeding hammock.",
           ]) );
   SetExits( ([
                "north" : SDM_ROOM + "/barn",
           ]) );
   SetObviousExits("north");
   SetInventory( ([
                    SDM_NPC + "/horse" : 4,
               ]) );
}