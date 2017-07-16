#include <lib.h>
#include "../ph.h"
inherit LIB_ROOM;
#define OUT "../../../towns/parva/room/path6"

static void create() {
   ::create();
   SetDomain("Havenwood");
   SetShort("Parva Hospital's Reception Room");
   SetClimate("indoors");
   SetTown("Parva");
   SetAmbientLight(40);
   SetLong("The Reception Room of Parva Hospital is semi-clean, with some "
           "spills and dirt marking the area, but compared to the "
           "town outside, it is immaculate.  Archways lead to the "
           "west and north, and a gently sloping ramp leads up.  Parva "
           "is to the north.");
    SetItems( ([
                 ({ "parva hospitals reception room","room","hospital" }) :
                    (: GetLong() :),
                 ({ "ramp" }) :
                    "The ramp leads to the floor above.  It appears "
                    "well-trafficked.  Hidden behind the ramp, there "
                    "appears to be a hatchway.",
                 ({ "spills and dirt","dirt","spills","spill","dust","debris" }) :
                    "Spills, vaguely remiscent of fresh and dried "
                    "blood, speckle the floor.  Dirt and dust mix in "
                    "with other random debris.  Most of it is in the "
                    "well-travelled patches, and attempts have been "
                    "made to tidy up.",
                 ({ "archways","archway","patterns","pattern" }) :
                    "The archways lead into the other parts of the hospital, or "
                    "outside.  There is one to the north and one to the west.  "
                    "Though simple in design, they have some decorative "
                    "patterns painted on, such as lines of varying thickness "
                    "and spirals.",
            ]) );
    SetItemAdjectives( ([
                          "room" : ({ "of","parva","room","reception" }),
                          "ramp" : ({ "gently","sloping" }),
                     ]) );
   SetSmell( ([
                "default" : "Smells of the sick cling to the walls.",
           ]) );
   SetListen( ([
                 "default" : "Groans and clamor constantly fill the hospital.",
            ]) );
   SetExits( ([
                "west" : PR + "/room2",
                "up" : PR + "/room4",
                "down" : PR + "/storage",
                "out" : "/domains/havenwood/towns/parva/room/path6",
           ]) );
   SetDoor("down",PR + "/hatch");
   SetInventory( ([
                    PN + "/hurt" : 5,
                    PN + "/janitor" : 1,
                    PN + "/ycleric" : 2,
               ]) );
}
