// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("inside a forest");
   SetLong("Paths appear and disappear in all directions, hinting "
           "at trampled brush and then fading into nothingness.  "
           "The trees thicken to the east, but thin to the west.  "
           "There are more trees to the north and south.");
   SetItems( ([
                ({ "paths","path" }) :
                   "The paths do not actual exist, but seem to "
                   "exist by a trick of the eye.",
                ({ "trampled brush","brush" }) :
                   "Some of the brush in this area has been trampled, "
                   "but nothing forms a cohesive trail.",
                ({ "trees","tree","forest" }) :
                   "There are trees everywhere.  This is a forest.  "
                   "The trees thin to the west and thicken to the "
                   "east, shutting out some of the sparse light.",
           ]) );
   SetSmell( ([
                "default" : "A rich earthy scent hangs in the air.",
           ]) );
   SetListen( ([
                 "default" : "A bird caws deeper in the forest.",
            ]) );
   SetInventory( ([
                    FOREST_NPC + "hunter" : 3,
                    FOREST_NPC + "reclusem" : 2,
               ]) );
   SetExits( ([
                "north" : AVERATH_ISLAND + "6,-3,0",
                "west" : AVERATH_ISLAND + "5,-4,0",
                "east" : AVERATH_ISLAND + "7,-4,0",
                "south" : AVERATH_ISLAND + "6,-5,0",
           ]) );
}
