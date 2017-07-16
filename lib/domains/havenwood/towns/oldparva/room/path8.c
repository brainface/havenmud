#include <lib.h>
#include "parva.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Parva");
   SetDomain("HavenWood");
   SetClimate("temperate");
   SetShort("a north-south road in Parva");
   SetLong("This road goes to the north and south "
           "through Parva.  It is dusty and worn, "
           "surrounded by buildings to the west and "
           "east.  Neither appear enterable from here.");
   SetItems( ([
                ({ "Parva road","road","path","parva" }) :
                   (: GetLong :),
                ({ "ramshackle buildings","building","buildings" }) :
                   "Buildings rise from the ground to either side "
                   "of the road.  None appear to be enterable "
                   "from this side; it is necessary to go around "
                   "to their front sides in the south.", 
                ({ "dirt ground","dirt","ground" }) :
                   "The road is formed from dirt.  No cobblestones "
                   "or boards keep down the dust or level the "
                   "ground.",
           ]) );
   SetItemAdjectives( ([
                         "road" : ({ "parva","north-south","dusty",
                                     "worn" }) ,
                         "buildings" : ({ "ramshackle" }),
                         "ground" : ({ "dirt" }),
                    ]) );
   SetListen( ([
                 "default" : "Parva's citizens noisily go about their "
                    "business.",
            ]) );
   SetSmell( ([
                "default" : "The salty ocean's smell dominates one's "
                   "senses.",
           ]) );
   SetExits( ([
                "south" : P_ROOM + "/path5",
           ]) );
}
