#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("on a picnic platform");
   
   SetLong("Placed carefully on the wet meadow is a picnic platform, "
           "which is made of some soft colored wood.  Some tall "
           "and ambitious grass pokes up from between boards that were "
           "used on the platform, but most of the grass grows to the "
           "sides of the platform.  To the west, there seems to be some "
           "sort of trail.  To the east and south, the West Wood "
           "blocks passage.  To the north, the meadow continues.");
   SetItems( ([
                ({ "picnic platform","platform" }) :
                   (: GetLong :),
                ({ "soft colored wood","soft wood","colored wood",
                   "wood","boards","board","tall ambitious grass",
                   "tall grass","grass","ambitious grass" }) :
                   "The boards used to make the platform are much like "
                   "those to the west used on the trail.  They are lain "
                   "side by side and then attached together by "
                   "perpendicular boards.  Some grass pokes through the "
                   "space between the boards.",
                ({ "meadow grass","grass" }) :
                   "Most of the grass in the meadow grows thick just "
                   "beyond the edges of the platform.  It is green and "
                   "healthy and very robust.",
                ({ "narrow trail","trail" }) :
                   "There is a trail to the west that is built on "
                   "boards.  It takes a north-south direction.",
                ({ "west wood","wood","woods","tree","trees" }) :
                   "The trees of the West Wood grow thick and strong to "
                   "the south and east, blocking all passage in those "
                   "directions.",
                ({ "beautiful meadow","meadow" }) :
                   (: GetLong :),
           ]) );
   SetItemAdjectives( ([
                         "meadow" : ({ "wet" }),
                         "grass" : ({ "ambitious","robust","green",
                                     "thick" }),
                    ]) );
   SetListen( ([
                 "default" : "The grass makes slight noise in the wind.",
            ]) );
   SetSmell( ([
                "default" : "The air smells fresh and clean.",
           ]) );
   SetExits( ([
                "north" : H_ROOM + "meadow_6",
                "west"  : H_ROOM + "trail_07",
           ]) );
   SetInventory( ([
                    H_NPC + "pic_ad" : 2+random(3),
                    H_NPC + "pic_kid" : 3+random(3),
               ]) );
}
