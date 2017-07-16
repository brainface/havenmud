#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("on a trail");
   SetDomain("WestWood");
   SetLong("Trees and other plants crowd around the boards, draping "
           "themselves all over and blocking clear views in any "
           "direction.  The boards stretch to the southwest and east, "
           "growing longer and bending more to the east and shortening "
           "to the southwest.  The trail remains narrow in both "
           "directions.");
   SetItems( ([
                ({ "narrow trail","trail" }) :
                   (: GetLong :),
                ({ "west wood","tree","trees","wood","woods",
                   "plant","plants","underbrush","brush","forest" }) :
                   "The West Wood grows clear in all directions, "
                   "flourishing in the rich ground in this area.  "
                   "Trees and many other plants make up the forest.",
                ({ "rich ground","ground" }) :
                   "The ground is rich and slightly moist, making it "
                   "wonderful for growing things in.  It slants "
                   "down to the southwest and keeps a steady but gentle "
                   "climb to the east.",
                ({ "boards of wood","board","boards",
                   "planks","plank","wood" }) :
                   "The planks are long and balanced between supports.  "
                   "They seem to shrink in size to the southwest, turning "
                   "into more a staircase than a trail.  Supports are "
                   "used to keep the boards off the ground and to mend "
                   "them together.",
                ({ "wood supports","support","supports","wood" }) :
                   "The supports are placed at either side of the "
                   "wooden planks.  They look like they were made by "
                   "chopping up another plank and stacking it up in "
                   "little squares.",
           ]) );
   SetItemAdjectives( ([
                         "board" : ({ "wooden","wood","planks of",
                                      "plank of","board of","boards of" }),
                         "supports" : ({ "wooden","wood" }),
                    ]) );
   SetListen( ([
                 "default" : "Wind brushes through the West Wood.",
            ]) );
   SetSmell( ([
                "default" : "The air is fresh and clean.",
           ]) );
   SetExits( ([
                "east"      : H_ROOM + "trail_05",
                "southwest" : H_ROOM + "trail_03",
           ]) );
   SetInventory( ([
                    H_NPC + "hiker" : 1,
               ]) );
}
