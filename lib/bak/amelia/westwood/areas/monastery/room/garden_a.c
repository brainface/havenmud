#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("in a garden");
   SetDomain("WestWood");
   SetLong("A soft green grass covers the ground, hiding from sight "
           "all brown earth and any ugly rocks.  Rows of nicely "
           "arranged rocks mark the space for the growing plants "
           "seperately from the places the grass may grow.  Inside those "
           "rocks, all grass has been removed and rich brown soil can "
           "be viewed between the flowers and bushes that grow there.  "
           "A gate leads out of the stone walls to the west, and "
           "it is possible to go north and east through the garden.");
   SetItems( ([
                ({ "soft green grass","soft grass","green grass",
                   "grass","ground" }) :
                   "The grass grows everywhere, it seems, but the "
                   "rocks seperate it from the other plants so that "
                   "it doesn't take over.  It flourishes extremely "
                   "well wherever it is growing.",
                ({ "rich brown soil","rich soil","brown soil","soil",
                   "brown earth","earth" }) :
                   "The grass covers the ground outside of the areas "
                   "surrounded with rocks, but inside them, some very "
                   "rich soil exists, dark and moist.",
                ({ "nicely arranged rocks","nicely arranged rock",
                   "arranged rocks","arranged rocks","rock","rocks",
                   "row","rows" }) :
                   "The only rocks that can be seen here are in rows, "
                   "arranged to block the grass from growing where the "
                   "gardener wants other plants to grow.",
                ({ "growing flowers","growing flower","flowers",
                   "flower" }) :
                   "Many flowers grow in the rich soil that was laid "
                   "especially for them.  They come in many colors, "
                   "shapes, and sizes.",
                ({ "growing bushes","growing bush","bushes","bush" }) :
                   "The bushes are stuck in to compliment the flowers "
                   "around them, and some are even in bloom.",
                ({ "stone walls","stone wall","walls","wall",
                   "stone" }) :
                   "The stone walls seperate the garden from the rest "
                   "of the world.  A gate leads out through it to the "
                   "west.",
           ]) );
   SetListen( ([
                 "default" : "Some birds chirp in the distance, beyond "
                    "the walls.",
            ]) );
   SetSmell( ([
                "default" : "The fragrances of the flowers fill the "
                   "air.",
           ]) );
   SetExits( ([
                "east"  : M_ROOM + "garden_b",
                "west"  : M_ROOM + "path",
                "north" : M_ROOM + "garden_c",
           ]) );
   SetDoor("west",M_ROOM + "gate");
   SetInventory( ([
                    M_NPC + "gardener" : 1,
                    M_NPC + "monk_c" : random(2)+1,
                    M_NPC + "monk_h" : 2+random(2),
               ]) );
}
