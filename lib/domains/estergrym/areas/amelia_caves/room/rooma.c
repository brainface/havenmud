// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
#define ROAD "/domains/estergrym/virtual/grymxoria_road/40,0"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("a dark tunnel");
   SetLong("Dark rock absorbs much of the light which comes from above, "
           "at least, what little of it makes it this far down in the "
           "first place.  The rough walls are damp and cold, but the "
           "path here has been smoothed by the tred of many feet.");
   SetItems( ([
                ({ "dark rock","rock" }) :
                   " The dark rock absorbs the light.",
                ({ "light from above","light" }) :
                   "The light is too faint to look at.",
                ({ "rough walls","rough wall","wall","walls" }) :
                   "Water drips off the rough edges of the wall.",
                ({ "rough edges","rough edge","edges","edge","rough spot",
                   "rough spots","spot","spots" }) :
                   "The rough spots on the walls are damp and wet.",
                ({ "smooth path","path" }) :
                   "So many beings have pitter-pattered across this "
                   " path that it has been worn smooth.",
           ]) );
   SetListen( ([
                 "default" : "Water drips farther down the tunnel.",
            ]) );
   SetSmell( ([
                "default" : "The tunnel smells musty and damp.",
           ]) );
   SetInventory( ([
                    C_NPC + "rat" : 1,
                    C_OBJ + "dullrock" : 1,
               ]) );
   SetExits( ([
                "down" : C_ROOM + "roomb",
                "southeast" : ROAD,
           ]) );
}
