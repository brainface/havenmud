#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("in a meadow");
   SetDomain("WestWood");
   SetLong("Trees make a shady appearance far on to the north and east, "
           "but the meadow continues in that direction for a ways yet.  "
           "A trail made of planks of wood climbs in a north-south "
           "manner to the west, where the meadow continues on some "
           "more.  A miry pond is towards the middle of this small "
           "area in the meadow.  It seems to fold into the earth and "
           "disappear.");
   SetItems( ([
                ({ "wide meadow","meadow","small area","area" }) :
                   (: GetLong :),
                ({ "west wood","trees","tree","wood","woods" }) :
                   "The West Wood shows up to the north and the east, "
                   "but enters into hiding in all other directions.  "
                   "Its trees are large and fringe the edges of the "
                   "meadow.",
                ({ "board trail","trail","boards","board",
                   "planks","plank","wood","wooden boards",
                   "wooden board" }) :
                   "Wooden boards make up a trail off to the west.  "
                   "The trail goes to the north and south, starting to "
                   "curve on its northern end.  It seems to head "
                   "more towards the northeast there.",
                ({ "miry pond","pond","mire","water","earth","fold" }) :
                   "The pond is sunk deep into the earth, like "
                   "an inverse hill.  It has no entrance and no "
                   "exits, but one could be imagined at either end of "
                   "the slight current going through.  It begins in a "
                   "fold of earth, and ends in one too.",
           ]) );
   SetListen( ([
                 "default" : "Buzzing noises flit around the pond.",
                 "pond" : "The pond itself has no sound, but there "
                    "seems to be lots of sound around it.",
            ]) );
   SetSmell( ([
                "pond" : "The pond is slightly rank in smell, as if the "
                   "minimal current is not enough to flush it through of "
                   "any buildup.",
           ]) );
   SetExits( ([
                "north" : H_ROOM + "meadow_4",
                "south" : H_ROOM + "meadow_6",
                "east"  : H_ROOM + "meadow_8", 
                "west"  : H_ROOM + "trail_09",
           ]) );
   SetInventory( ([
                    H_NPC + "doe" : 2,
                    H_NPC + "stag" : 1,
               ]) );
}
