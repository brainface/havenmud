#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("on a porch");
   SetDomain("WestWood");
   SetLong("The porch is made of plain, solid wood that was used to "
           "construct both the porch and the cabin that porch is "
           "attached to.  The West Wood and its trees have pushed "
           "away from the cabin, not crowding it as they have "
           "crowded the trail that heads off to the west.  A door "
           "leads into the cabin.");
   SetItems( ([
                ({ "plain porch","porch" }) :
                   (: GetLong :),
                ({ "plain solid wood","wood" }) : 
                   "The wood used on the cabin and the porch is "
                   "rough and could use a good sanding.  It is, "
                   "however, quite solid and sturdy, and was "
                   "used well in the construction.",
                ({ "solid cabin","cabin" }) :
                   "The cabin is not a grand structure or anything "
                   "of great interest, but it is a place to go to "
                   "rest from the travails of the trail heading up "
                   "to it, and a place to get out of the cold and "
                   "the rain and the wind and the snow.  A plain door "
                   "leads inside it.",
                ({ "west wood","wood","woods","tree","trees" }) :
                   "The trees do not press up against the cabin and the "
                   "porch, but keep their distance and avoid it.  "
                   "Some nearby stumps show that the avoidance may not "
                   "be voluntary or coincidental.",
                ({ "tree stumps","stump","stumps" }) :
                   "The trees nearest the cabin were cut down, and used "
                   "to build it or perhaps as firewood.  However, the "
                   "stumps have been left behind to rot and disappear.",
                ({ "crowded trail","trail" }) :
                   "The trail is crowded by the West Wood, but seems to "
                   "hold its own and have plenty of space.  It heads to "
                   "the west, going down.",
           ]) );
   SetItemAdjectives( ([
                         "stump" : ({ "tree" }),
                         "wood" : ({ "rough","sturdy","plain","solid" }),
                    ]) );
   SetListen( ([
                 "default" : "Noise comes from the cabin.",
            ]) );
   SetSmell( ([
                "default" : "A fire must be burning near, as the smoke "
                   "can be smelled.",
           ]) );
   SetExits( ([
                "west" : H_ROOM + "trail_16",
           ]) );
   SetEnters( ([
                 "cabin" : H_ROOM + "cabin",
            ]) );
   SetDoor("cabin",H_ROOM + "cabin_dr");
   SetInventory( ([
                    H_NPC + "cab_qu" : 2,
                    H_NPC + "cab_man" : 1,
               ]) );
}
