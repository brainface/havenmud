#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("on a trail");
   SetDomain("WestWood");
   SetLong("Scraggly grass grows up next to the wooden boards of the "
           "narrow trail heading out into the West Wood.  The "
           "meadow skips off to the south, with the trail following "
           "along its edge to the southwest.  A some weak flowers "
           "dot the sides of these wooden planks, but not many.");
   SetItems( ([
                ({ "southern meadow","meadow" }) :
                   "The meadow is to the south, where the grass grows "
                   "thick and the flowers are plentiful.  It seems to "
                   "spread out even more the farther south one heads.",
                ({ "weak flowers","flowers","flower" }) :
                   "The flowers that grow around here are pale in color "
                   "and seem slightly wilted, either from too much "
                   "sun or too little.",
                ({ "west wood","wood","woods","tree","trees","forest" }) :
                   "The trees of the West Wood grow to the north, east "
                   "and west, but a trail breaks through to the north.  "
                   "The forest itself is not particulary strange or "
                   "significant.",
                ({ "narrow trail","trail" }) :
                   (: GetLong :),
                ({ "scraggly grass","grass" }) :
                   "The grass grows all over, except in the West Wood, "
                   "but seems to be flourishing best farther south, deep "
                   "into the meadow.  Near the boards and under them, "
                   "the grass is weak and limp, pale from the lack of "
                   "sunlight it recieved there.  The ground is also "
                   "more dry and dusty as it moves into the forest, "
                   "while it is damper to the south.",
                ({ "wooden boards","wooden board","board","boards",
                   "wooden plank","wooden planks","plank","planks",
                   "wood" }) :
                   "The trail is made of wooden planks, lined up "
                   "as straight as possible with the curve here.  "
                   "They seem firmly placed on the ground, but to "
                   "the southwest they look slightly crooked.  "
                   "They are flat and straight to the north.",
                ({ "solid ground","ground","dirt","earth" }) :
                   "The ground is dry and solid here, very firm and "
                   "packed hard.  It seems a bit more damp to the south.",
           ]) );
   SetItemAdjectives( ([
                         "ground" : ({ "solid" }),
                         "boards" : ({ "wooden","wood","planks of",
                                       "plank of","boards of",
                                       "board of" }),
                         "flowers" : ({ "weak" }),
                         "meadow" : ({ "south" }),
                    ]) );
   SetSmell( ([
                "default" : "The forest puts a dampened smell of "
                   "deep down earth-freshness in the air.",
           ]) );
   SetListen( ([
                 "default" : "Something trinkles to the north.",
            ]) );
   SetExits( ([
                "southwest" : H_ROOM + "trail_10",
                "south"     : H_ROOM + "meadow_4",
                "north"     : H_ROOM + "trail_12",
           ]) );
}
