#include <lib.h>
inherit LIB_FISHING;
#include "../hiker.h"

static void create() {
   fishing::create();
   SetClimate("indoors");
   SetDomain("WestWood");
   SetAmbientLight(15);
   SetShort("under a bridge");
   SetLong("The bridge is above, mostly dry as it is quite high up "
           "off of the water.  It completely shadows the entire stream "
           "here, making it dark and gloomy.  A mass of branches has "
           "clogged together up against the west side of the bridge, "
           "making it impossible to go that way, but to the east "
           "is open water and open air.");
   SetItems( ([
                ({ "high bridge","bridge" }) :
                   "The bridge is old and dusty; its lack of care "
                   "apparent from this side of it.  It is plenty "
                   "large enough to hide the sun, moon, and stars "
                   "from casting light in here.",
                ({ "dark stream","steam","water" }) :
                   (: GetLong :),
                ({ "mass of branches","mass","branches","branch" }) :
                   "The branches are all tangled together in a "
                   "mass of chaos.  They block movement to the west, "
                   "and hide any further view in that direction.",
           ]) );
   SetItemAdjectives( ([
                         "stream" : ({ "dark" }),
                         "bridge" : ({ "old","dusty" }),
                    ]) );
   SetListen( ([
                 "default" : "Pitter-pattering noises come from the "
                    "bridge above, and water spills over the branches "
                    "to the west.",
            ]) );
   SetSmell( ([
                "default" : "The refreshing stream smells are "
                   "almost overpowered by the dankness of the "
                   "bridge above.",
           ]) );
   SetExits( ([
                "east" : H_ROOM + "stream",
           ]) );
   SetInventory( ([
                    H_NPC + "spider" : 1,
               ]) );
}
