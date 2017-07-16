// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("beneath an eagle's nest");
   SetLong("Twigs and branches arranged in a cylinder fashion "
           "form a two-feet high nest that perches in a tree hanging "
           "over the edge of the sea cliffs.  Far below, the "
           "beach is attacked by wave after wave of bashing "
           "ocean.  The forest continues to the north and west, "
           "While the cliffs drop on the east and south sides.");
   SetItems( ([
                ({ "forest" }) : (: GetLong :),
                ({ "bald eagle's nest","nest","twigs","twig",
                   "branches","branch" }) :
                   "Each stick carefully places, the resultant "
                   "nest has the appearance of a hurricane "
                   "or a child's creation.  Nestled in a "
                   "branch hanging out over the edge of the sea "
                   "cliffs, it conceives of the idea of tiny "
                   "bald eagles plunging to their deaths below.",
                ({ "trees","tree" }) :
                   "Trees clutter the area, thickening to the "
                   "north and west.  One particularly large "
                   "tree holds the bald eagle's nest.  Its "
                   "roots create a little cave.",
                ({ "bald eagle tree","tree", }) :
                   "The tree with the bald eagle's nest has "
                   "large roots that create a small cave.  "
                   "Wind has eroded the dirt that used to surround "
                   "them.",
                ({ "small cave","roots","root","cave" }) :
                   "The powerful force of the wind has picked out "
                   "the dirt that used to occupy the space beneath "
                   "the roots, forming a small cave with an "
                   "entrance the size of a young human.",
                ({ "sea cliffs","cliffs","cliff" }) :
                   "A sheer face cuts off the forest, leaving a "
                   "drop of many human lengths before the beach "
                   "meets the sea.",
           ]) );
   SetItemAdjectives( ([
                         "nest" : ({ "bald","eagle's" }),
                         "cliffs" : ({ "sea" }),
                    ]) );
   SetListen( ([
                 "default" : "Waves crash loudly below.",
            ]) );
   SetSmell( ([
                "default" : "A delicate salt scent mixes with the "
                   "rich aroma of earth and fertile dirt.",
           ]) );
   SetExits( ([
                "north" : AVERATH_ISLAND + "8,-4,0",
                "west" : AVERATH_ISLAND + "7,-5,0",
           ]) );
   SetEnters( ([
                 "cave" : FOREST_ROOMS + "forestcave",
            ]) );
   SetInventory( ([
                    FOREST_NPC + "baldeagle" : 2,
                    FOREST_NPC + "immatureeagle" : 2,
               ]) );
}
