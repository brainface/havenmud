#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("on a trail");
   SetDomain("WestWood");
   SetLong("The trail goes both south and northwest, cutting through the "
           "West Wood.  The planks of wood used to mark the path and "
           "make the going easy stop slightly to the northwest as the "
           "trail turns, revealing the muddy dirt of trampled trails.  "
           "To the south, there seem to be even more planks than there "
           "are at this end of the trail.");
   SetItems( ([
                ({ "planks of wood","plank of wood","planks","plank",
                   "wooden planks","wooden plank","board","boards" }) :
                   "The planks are of a thin but solid wood that "
                   "bends down and is not necessarily slanted level "
                   "to the ground.  They end shortly ahead, where the "
                   "mud picks up.",
                ({ "trampled trail","trail" }) :
                   (: GetLong :),
                ({ "west wood","wood","woods","tree","trees" }) :
                   "The West Wood surrounds the trail, its trees "
                   "hanging over and filling out the sides and some "
                   "especially small ones growing right up against the "
                   "planks.  This trail must truly cut through the woods.",
                ({ "muddy dirt","dirt","mud","ground","thin area",
                   "area" }) :
                   "Ironicly enough, the dirt under the planks is "
                   "dry and solid, but as soon as the planks end, the "
                   "trail turns to mud and is slushy and icky.  The "
                   "West Wood pushes right against that mud, leaving the "
                   "thinnest area to walk around.  That thin area is "
                   "turning mucky, also.",
           ]) );
   SetListen( ([
                 "default" : "The rushing noise of water comes from the "
                    "south.",
            ]) );
   SetSmell( ([
                "default" : "The dirt beyond the planks has a distinct "
                   "odor to it that drifts around, not entirely "
                   "unpleasant, but present.",
                "mud" : "Mud has never been the most pleasant of "
                   "things, but doesn't necessarily smell terrible.  "
                   "This particular mud is only slightly smelly of "
                   "rich earth and minerals and whatever else sits "
                   "dormant until water mixes in with it.",
           ]) );
   SetExits( ([
                "northwest" : H_ROOM + "trail_14",
                "south"     : H_ROOM + "trail_12",
           ]) );
}
