#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("in a meadow");
   SetDomain("WestWood");
   SetLong("Chocolate lilies grow in a strip from the west heading to the "
           "north, where they start to thin and become more surrounded "
           "by grass than by each other.  Grass covers the ground like "
           "a thick green carpet, except to the east and south where "
           "the West Wood grows thick.  The meadow continues to the "
           "north and west.");
   SetItems( ([
                ({ "wide meadow","meadow" }) :
                   (: GetLong :),
                ({ "chocolate lilies","chocolate lily","lilies",
                   "lily" }) :
                   "A deep rich brown color seems almost painted on to "
                   "cup-like tops of the chocolate lilies.  They "
                   "fill out a strip of grass to the north and west, "
                   "darkening it and adding color and life to the area.",
                ({ "west wood","wood","woods","tree","trees" }) :
                   "The West Wood is thick and the trees are bright "
                   "and cheery.  It seems like they block all progress "
                   "to the south and east, but it looks possible to "
                   "push through to the southeast.",
                ({ "green grass","grass","ground","carpet" }) :
                   "The grass is hidden in a strip of chocolate lilies "
                   "that traverses the area from the west to the north.  "
                   "It is all, however, quite visible in other areas.  "
                   "It is thick and very green, looking like it has "
                   "flourished in this area for many years.",
           ]) );
   SetItemAdjectives( ([
                         "grass" : ({ "grass","green","thick",
                                      "grassy" }),
                         "tops" : ({ "cup-like" }),
                         "lilies" : ({ "deep","rich","brown",
                                       "chocolate" }),
                         "trees" : ({ "bright","cheery" }),
                    ]) );
   SetListen( ([
                 "default" : "Something rustles around in the trees.",
                 "west wood" : "Hidden in the West Wood, something "
                    "shakes the trees in a memorable way.  This is "
                    "definitely not an example of 'out of sight, out "
                    "of mind', as something about the shaking seems "
                    "insistant and purposeful.",
            ]) );
   SetSmell( ([
                "default" : "Outside air in meadows like this is always "
                   "fresh and sweet smelling.",
           ]) );
   SetSearch( ([
                 "west wood" : "The search through the trees reveals a "
                    "space to walk to the southeast.  The rustling "
                    "noise comes from that direction, also.",
            ]) );
   SetObviousExits("north, west");
   SetExits( ([
                "north"     : H_ROOM + "meadow_8",
                "southeast" : H_ROOM + "intrees",
                "west"      : H_ROOM + "meadow_6",
           ]) );
   SetInventory( ([
                    H_NPC + "hiker_l" : 1,
                    H_NPC + "grub" : 4+random(3),
               ]) );
}
