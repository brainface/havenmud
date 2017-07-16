#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("on a trail");
   
   SetLong("The forest's uneven ground causes the planks of wood to "
           "seek an easier trail; they turn to the northeast and "
           "south.  The forest closes in on the trail to the northeast, "
           "but there is a meadow off to the east side of the trail and "
           "it opens up to surround it to the south.");
   SetItems( ([
                ({ "West Wood","forest","woods","wood","tree","trees",
                   "trail","west wood" }) :
                   (: GetLong :),
                ({ "planks of wood","plank","planks","wood"
                   "board","boards","ground","uneven ground" }) :
                   "The boards turn here, going from the south to the "
                   "northeast.  It is a gradual turn, hardly effecting "
                   "the planks at all.",
                ({ "east meadow","meadow" }) :
                   "The meadow starts to the east, growing vibrant "
                   "grasses and flowers.",
                ({ "vibrant grasses","grasses","grass" }) :
                   "The grass is green and lively, growing with an "
                   "enthusiasm as it stretches towards the light.",
                ({ "beautiful flowers","flower","flowers",
                   "wildflowers","wildflower" }) :
                   "The flowers come in all shapes and sizes, but are "
                   "mostly small and short.",
           ]) );
   SetItemAdjectives( ([
                         "boards" : ({ "plank of","board of","wooden",
                                       "planks of","boards of","wood" }),
                         "grass" : ({ "vibrant" }),
                         "trail" : ({ "narrow","easier" }),
                         "flowers" : ({ "wild","beautiful","small", 
                                        "short","mostly" }),
                    ]) );
   SetListen( ([
                 "default" : "The forest is quiet.",
            ]) );
   SetExits( ([
                "northeast" : H_ROOM + "trail_11",
                "south"     : H_ROOM + "trail_09",
                "east"      : H_ROOM + "meadow_4",
           ]) );
   SetInventory( ([
                    H_NPC + "hiker" : random(2),
               ]) );
}
