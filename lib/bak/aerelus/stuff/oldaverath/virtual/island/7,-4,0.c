// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("near a large oak tree");
   SetLong("A giant oak tree soars through the air above, with "
           "a large canopy of leaves blocking out the sky.  "
           "A myriad of plants grow on the forest floor, including "
           "fiddlehead ferns, blueberry bushes, and amanitas.  "
           "The forest deepens to the east and south, but "
           "thins out to the north and west.  All cardinal directions "
           "are easily traversable.");
   SetItems( ([
                ({ "giant oak tree","tree","oak" }) :
                   "Many low-lying limbs branch off of the giant oak tree, "
                   "making it easy for even a small child to clamber up into "
                   "the forest canopy.",
                ({ "low-lying limbs","limbs","limb","branch","branches" }) :
                   "Firm branches fork off of the giant oak tree, providing "
                   "steady footing.",
                ({ "forest" }) : (: GetLong :),
                ({ "large canopy of leaves","canopy","leaves","leaf" }) :
                   "The leaves hang off of the trees, fluttering in the "
                   "gentle breeze.  They cut off vision of the sky.",
                ({ "myriad of plants","plants","plant","floor" }) :
                   "The forest floor is barely visible through a sheet "
                   "of ferns, blueberry bushes, and amanita mushrooms.",
                ({ "fiddlehead ferns","ferns","fern" }) :
                   "The ferns reach about waist-hieght on a normal adult "
                   "human male, never branching out into multiple stalks.",
                ({ "blueberry bushes","bushes","bush" }) :
                   "With spring-green leaves tinged with blue, the bushes "
                   "grow in clumps.",
                ({ "amanita mushrooms","mushrooms","mushroom","amanitas",
                   "amanita" }) :
                   "With bright orange-yellow caps, the amanita "
                   "mushrooms grow from bulbous stems in clusters "
                   "near the base of the oak tree.",
           ]) );
   SetItemAdjectives( ([
                         "oak" : ({ "giant","oak" }),
                         "limbs" : ({ "low-lying","firm" }),
                         "canopy" : ({ "large","canopy of","forest" }),
                         "plants" : ({ "myriad of","forest" }),
                         "ferns" : ({ "fiddlehead" }),
                         "bush" : ({ "blueberry" }),
                         "amanitas" : ({ "amanita" }),
                    ]) );
   SetSmell( ([
                "default" : "A rich odor of live and forest permeates the area.",
           ]) );
   SetListen( ([
                 "default" : "Birds sing with the rustling leaves.",
            ]) );
   SetInventory( ([
                    FOREST_NPC + "livedryad" : 2,
                    FOREST_NPC + "raven" : 1,
               ]) );
   SetExits( ([
                "up" : FOREST_ROOMS + "dryadtree",
                "east" : AVERATH_ISLAND + "8,-4,0",
                "west" : AVERATH_ISLAND + "6,-4,0",
                "south" : AVERATH_ISLAND + "7,-5,0",
                "north" : AVERATH_ISLAND + "7,-3,0",
           ]) );
}
