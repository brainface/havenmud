#include <lib.h>
#include "../ph.h"
inherit LIB_ROOM;

static void create() {
   ::create();
   SetTown("Parva");
   SetDomain("Havenwood");
   SetClimate("indoors");
   SetAmbientLight(40);
   SetShort("a hospital room");
   SetLong("Windows look out over Parva and the ocean, bathing the room in the "
           "bustle of the city and the calm of the waters.  Boats are scattered "
           "all around on the ocean.  Cots line the room "
           "in many rows, and archways lead out to the east and west.");
   SetItems( ([
                ({ "hospital room","hospital","room" }) : (: GetLong :),
                ({ "windows","window" }) :
                   "The windows are large and scenic, remaining open constantly.  "
                   "They provide a view of Parva and the ocean.",
                ({ "parva","city","town" }) :
                   "Parva is the town outside of this fair hospital.  "
                   "It sits right on the ocean.",
                ({ "ocean","waters","water" }) :
                   "The ocean stretches for miles beyond the mainland, speckled "
                   "with boats and tiny islands.  It is blue-green in appearance.",
                ({ "boats","boat" }) :
                   "The boats, most likely there for fishing, move slowly "
                   "through the ocean.  There are many in the waters just in "
                   "front of Parva.",
                ({ "tiny islands","island","islands","tiny island" }) :
                   "Small islands, no more than simple hunks of rock, sit out in the "
                   "ocean far beyond Parva.  The boats circle to avoid them.",
                ({ "cots","cot" }) :
                   "The cots are neatly prepared and arranged, with many near the "
                   "windows.",
                ({ "archways","archway" }) :
                   "The archways lead into more hospital rooms to the east and west.",
           ]) );
   SetListen( ([
                 "default" : "The sounds of Parva and the ocean waves are clearly "
                    "audible through the open windows.",
            ]) );
   SetSmell( ([
                "default" : "Damping the stuffy smells of the hospital are those of "
                   "the nearby ocean.",
           ]) );
   SetExits( ([ 
                "east" : PR + "/room4",
                "west" : PR + "/ward",
           ]) );
   SetInventory( ([
                    PN + "/poison" : 5,
                    PN + "/doctor" : 2,
                    PN + "/patient" : 3,
                    PN + "/janitor" : 1,
               ]) );
}
