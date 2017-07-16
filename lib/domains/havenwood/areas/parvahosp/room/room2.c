#include <lib.h>
#include "../ph.h"
inherit LIB_ROOM;

static void create() {
   ::create();
   SetDomain("Estergrym");
   SetClimate("indoors");
   SetAmbientLight(40);
   SetTown("Parva");
   SetShort("inside the Parva Hospital");
   SetLong("Cots line the walls and form a row in the center of this long chamber, "
           "which continues to the east.  Bright ambient lighting is supplied "
           "from some unknown source, and the floor is semi-dirty.  An archway "
           "leads to the east, and a ramp leads down to the basement.");
   SetItems( ([
                 ({ "parva hospital","hospital","room","chamber" }) :
                    (: GetLong :),
                 ({ "cots","cot","walls","wall" }) :
                    "Carefully kept beds line up along the walls and in the "
                    "center of the room, some of them knocked askew by overly "
                    "ambitious doctors or janitors.",
                 "floor" : "The floor is somewhat dirty, but mostly clean.",
                 "archway" : "It leads to the east, towards the entrance to the "
                             "hospital.",
                 "ramp" : "The ramp gently slopes down to the basement.",
                 "basement" : "The basement is down from here.",
           ]) );
   SetSmell( ([
                "default" : "Unpleasant, hospital smells linger in the room.",
           ]) );
   SetListen( ([
                 "default" : "A cacophonic symphony of moans and groans "
                 "eminates from all around.",
            ]) );
   SetExits( ([
                "down" : PR + "/quarantine",
                "east" : PR + "/entrance",
                "west" : PR + "/room3",
           ]) );
   SetInventory( ([
                    PN + "/patient" : 3,
                    PN + "/invalid" : 4,
                    PN + "/doctor" : 1,
                    PN + "/janitor" : 1,
               ]) );
}
