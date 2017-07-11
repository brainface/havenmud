#include <lib.h>
#include "../ph.h"
inherit LIB_ROOM;

static void create() {
   ::create();
   SetDomain("Havenwood");
   SetClimate("indoors");
   SetAmbientLight(40);
   SetTown("Parva");
   SetShort("the children's ward");
   SetLong("Cribs line parts of the wall to hold the smallest children and infants, "
           "and small bunks forms rows in the rest of the room.  A bright mural "
           "covers the walls, and the ceiling is painted like the sky.  This is an "
           "archway leading out to the east.");
   SetItems( ([
                ({ "cribs","crib" }) :
                   "The cribs are like small little boxes, made comfortable for "
                   "young babies.  Some large ones have sides with adjustable "
                   "heights.",
                ({ "bright mural","mural","wall","walls","ceiling" }) :
                   "A bright mural depicting laughing children and forest covers "
                   "the wall, with a sunny sky above on the ceiling.",
                ({ "room","ward" }) : (: GetLong :),
                ({ "archways","archway" }) :
                   "An archway leads out of the children's ward to the east.",
                ({ "small bunks","bunks","bunk" }) :
                   "Bunk beds, some stacked as many as three high, sit in "
                   "careful rows throughout the room.",
           ]) );
   SetItemAdjectives( ([
                         "mural" : ({ "bright","colorful" }),
                         "ward" : ({ "childrens","children" }),
                         "bunks" : ({ "small" }),
                    ]) );
   SetListen( ([
                 "default" : "Hyperactive children make lots of noise.",
            ]) );
   SetSmell( ([
                "default" : "The smell of dirty diapers and drooling children "
                   "hangs in the air.",
           ]) );
   SetExits( ([
                "east" : PR + "/room5",
           ]) );
   SetInventory( ([
                    PN + "/cnurse" : 2,
                    PN + "/hurtkid" : 4,
                    PN + "/hurtbaby" : 2,
                    PN + "/reckid" : 3,
                    PN + "/recbaby" : 1,
               ]) );
}
