#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("under a platform");
   SetDomain("WestWood");
   SetLong("Neatly organized piles of leaves and other forest debris "
           "are carefully ordered beneath this wooden platform.  "
           "They seem to be beginning to decompose; indeed, it is "
           "as if they are encouraged to, as mounds of dirt piled around "
           "look like the rich remains of the decomposition process.  "
           "One can move under the platforms to the south and east; "
           "the west and north are unattainable travel options due to "
           "the decomposing mounds.");
   SetItems( ([
                ({ "wooden platforms","wooden platform","platform",
                   "platforms" }) :
                   "There is a platform directly above, as well as "
                   "two others to the east and south.  It is possible "
                   "to go under the other ones, as well.  The platforms "
                   "are all very solid and strong, and are carefully "
                   "supported by some dead trees.",
                ({ "dead trees","dead tree","trees","tree","supports",
                   "support" }) :
                   "The dead trees have been fashioned into supports, "
                   "and they look like they are doing a very good job "
                   "of holding up the platforms.  The various mounds "
                   "of dirt and debris have been placed rather distant "
                   "from all of the supports.",
                ({ "heaps of rich dirt","heap of rich dirt","rich dirt",
                   "heap of dirt","heaps of dirt","dirt","mound",
                   "mounds","mounds of dirt","mound of dirt",
                   "rich soil","soil" }) :
                   "Rich soil exists as mounds of dirt here; it "
                   "is the decomposed version of the forest debris "
                   "that fills  the other piles.  A few plants have "
                   "tried growing in it, but most have been pulled out "
                   "and tossed to piles that have yet to decompose.",
                ({ "neatly organized piles of forest debris",
                   "neatly organized pile of forest debris",
                   "neatly organized pile of debris","forest debris",
                   "neatly organized piles of debris","debris",
                   "organized piles of debris","organize pile of debris",
                   "organized piles of forest debris","organized pile",
                   "organized pile of forest debris","organized piles",
                   "piles of debris","pile of debris","piles","pile",
                   "pile of forest debris","piles of forest debris",
                   "forest debris","debris","leaves","leaf",
                   "decomposing mounds","decomposing mound","mounds",
                   "mound","twigs","twig","sticks","stick","plant",
                   "plants" }) :
                   "Twigs and sticks and leaves and all sorts of "
                   "the things found in forests lie on the ground "
                   "here.  Neat piles are formed out of them, "
                   "organized in such a way as to maximize their "
                   "ability to decay.  The heaps of rich dirt are "
                   "the product of this process.",
                ({ "dirt ground","soft ground","ground" }) :
                   "The ground has many different piles and mounds "
                   "covering it.  The supports also come out of the "
                   "soft ground, holding up the platform so that it "
                   "doesn't come crashing down on everything.",
           ]) );
   SetListen( ([
                 "default" : "The area is quiet.",
            ]) );
   SetSmell( ([
                "default" : "Strong smells of dirt and the like "
                   "permeate the air.",
           ]) );
   SetExits( ([
                "east"  : M_ROOM + "ground_b",
                "south" : M_ROOM + "ground_d",
           ]) );
}
