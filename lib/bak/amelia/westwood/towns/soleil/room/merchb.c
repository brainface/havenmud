#include <lib.h>
#include "../soleil.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Soleil");
   SetDomain("WestWood");
   SetClimate("indoors");
   SetAmbientLight(55);
   SetShort("a hot kitchen");
   SetLong("Smoke hangs near the ceiling from a "
           "failed batch of cookies, slowly "
           "drifting out of an open window on the "
           "north side of the house.  A doorway "
           "leads south; it is the only exit.  "
           "There is a large oven in the room "
           "and a cooling rack.");
   SetItems( ([
                ({ "hot kitchen","kitchen","room" }) :
                   (: GetLong :),
                ({ "smokey ceiling","ceiling","smoke" }) :
                   "The ceiling has smoke and "
                   "water vapor hanging right near "
                   "it.  The gasses mix and slowly "
                   "disperse into the outside "
                   "through a window.",
                ({ "open window","window" }) :
                   "The window is very plain and "
                   "has no glass in it; it is "
                   "simply open to the fresh air.",
                ({ "south doorway","doorway" }) :
                   "The doorway to the south "
                   "is the only exit from the "
                   "kitchen.",
                ({ "large oven","oven" }) :
                   "The oven is old and "
                   "appears to be used frequently.",
                ({ "cooling rack","rack" }) :
                   "The cooling rack is not in "
                   "use right now, but the "
                   "smells in the room suggest "
                   "that it will be soon.",
           ]) );
   SetItemAdjectives( ([
                         "kitchen" : ({ "hot" }),
                         "ceiling" : ({ "smokey" }),
                         "window" : ({ "open" }),
                         "doorway" : ({ "south" }),
                         "oven" : ({ "large","old" }),
                         "rack" : ({ "cooling" }),
                    ]) );
   SetSmell( ([
                "default" : "The smells of fresh-baked "
                   "sweets fill the air.",
           ]) );
   SetListen( ([
                 "default" : "Light voices whisper from the "
                    "south.",
            ]) );
   SetExits( ([
                "south" : S_ROOM + "mercha",
           ]) );
   SetInventory( ([
                    S_NPC + "trainer_healing" : 1,
               ]) );
}
