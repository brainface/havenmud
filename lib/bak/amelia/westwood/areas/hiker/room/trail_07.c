#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("on a trail");
   SetDomain("WestWood");
   SetLong("Planks of wood mark the trail across this wide and beautiful "
           "meadow.  Fresh grass grows across the meadow, speckled with the "
           "occasional tree and many beautiful wildflowers.  The planks head to "
           "the north into more meadow and to the south, where the forest closes "
           "in again.");
   SetItems( ([
                ({ "meadow trail","trail" }) :
                   (: GetLong :),
                ({ "planks of wood","plank","planks",
                   "wood","boards","board" }) :
                   "Wooden boards form the trail, raised up off the ground "
                   "by supports are either end.  They sag down in the middle, "
                   "and about about nine feet long each.",
                ({ "wood supports","supports","support","wood",
                   "planks","plank" }) :
                   "The supports are chopped up pieces of planks.  They "
                   "were cut into squares and stacked up on top of each other, "
                   "then placed at either end of the planks.",
                ({ "wide beautiful meadow","meadow","field" }) :
                   (: GetLong :),
                ({ "fresh grass","grass","ground" }) :
                   "The grass is a pale green, but it looks very healthy and "
                   "quite robust.  Wildflowers hide in its cover.",
                ({ "beautiful wildflowers","wildflowers","wildflower",
                   "flower","flowers", }) :
                   "The flowers are all over, and many different kinds exist.  "
                   "Most are small and hang near to the ground.",
                ({ "west wood","wood","woods","forest","tree","trees" }) :
                   "The trees of the West Wood are off far to the west and "
                   "east, closer to the south.  To the north, they are not "
                   "visible.",
           ]) );
   SetItemAdjectives( ([
                         "meadow" : ({ "wide","beautiful" }),
                         "boards" : ({ "planks of","plank of","wood",
                                       "boards of","board of","wooden" }),
                         "flowers" : ({ "beautiful","wild","small" }),
                         "supports" : ({ "wooden","wood" }),
                    ]) );
   SetListen( ([
                 "default" : "Some birds chirp.",
            ]) );
   SetSmell( ([
                "default" : "The air is fresh, and the flowers can be smelled.",
           ]) );
   SetExits( ([
                "north" : H_ROOM + "trail_08",
                "south" : H_ROOM + "trail_06",
                "west"  : H_ROOM + "meadow_3",
                "east"  : H_ROOM + "meadow_7",
           ]) );
   SetInventory( ([
                    H_NPC + "hiker" : random(3),
               ]) );
}
