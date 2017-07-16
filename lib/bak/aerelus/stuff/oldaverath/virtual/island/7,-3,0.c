// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("inside a well-lit forest");
   SetLong("Devil's clubs grow in clusters at the base of a large silver "
           "birch, interspersed with ferns and other bushes.  The forest "
           "thins to the north, but thickens to the south.  A few "
           "mulberry trees grow in the area.");
   SetItems( ([
                ({ "well-lit forest","forest" }) : (: GetLong :),
                ({ "devil's clubs","clubs","club","clusters","cluster" }) :
                   "The devil's clubs spring from the ground with sharp "
                   "spines covering them.",
                ({ "large silver birch","birch","tree" }) :
                   "Dark brown bark covers the bottom of the silver birch, "
                   "but it slowly fades into a silver-white near the top.",
                ({ "fiddlehead ferns","ferns","fern" }) :
                   "Spring green fiddlehead ferns fill the spaces between "
                   "the trees.",
                ({ "blueberry bushes","bushes","bush" }) :
                   "Blueberry bushes grow in tandem with the devil's clubs and "
                   "fiddlehead ferns.",
                ({ "mulberry trees","trees","tree","mulbery","mulberries" }) :
                   "The mulberry trees squat closer to the ground than the "
                   "birches, flowering with plump white mulberries.",
           ]) );
   SetItemAdjectives( ([
                         "clubs" : ({ "devil's" }),
                         "birch" : ({ "large","silver","birch",
                                      "spring","green" }),
                         "ferns" : ({ "fiddlehead" }),
                         "bushes" : ({ "blueberry" }),
                         "mulberries" : ({ "mulberries","mulberry","plump",
                                           "white" }),
                    ]) );
   SetListen( ([
                 "default" : "The wind rustles through the trees.",
            ]) );
   SetSmell( ([
                "default" : "Rich forest scents fill the air.",
           ]) );
   SetInventory( ([
                    FOREST_NPC + "hunter" : 1,
                    FOREST_NPC + "elk" : 3,
               ]) );
   SetExits( ([
                "west" : AVERATH_ISLAND + "6,-3,0",
                "east" : AVERATH_ISLAND + "8,-3,0",
                "south" : AVERATH_ISLAND + "7,-4,0",
                "north" : AVERATH_ISLAND + "7,-2,0",
           ]) );
}
