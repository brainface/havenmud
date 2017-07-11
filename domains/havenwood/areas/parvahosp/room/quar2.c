#include <lib.h>
#include "../ph.h"
inherit LIB_ROOM;

static void create() {
   ::create();
   SetDomain("Havenwood");
   SetClimate("indoors");
   SetAmbientLight(40);
   SetTown("Parva");
   SetShort("a quarantined area");
   SetLong("Cots take up the bulk of the floor space, and some in this room are "
           "stacked on top of each other so that there is more space for "
           "patients.  Red signs clearly explain that this area is "
           "quarantined.  There is an exit to the east.");
   SetItems( ([
                ({ "quarantined area","area","room","quarantine" }) :
                   (: GetLong :),
                ({ "cots","cot" }) :
                   "Clean, pressed sheets are folded around the cots, "
                   "neatly and carefully.",
                ({ "clean pressed sheets","sheets","sheet" }) :
                   "In dingy, old colors, the sheets are curled around "
                   "the cots and neatly folded into place.",
                ({ "red signs","signs","sign" }) :
                   "Carefully painted with small decorations like flowers and "
                   "forests, the red signs say that this is "
                   "a restricted and dangerous area due to disease.",
           ]) );
   SetItemAdjectives( ([
                         "sheets" : ({ "clean","pressed" }),
                         "signs" : ({ "red","decorated" }),
                    ]) );
   SetListen( ([
                 "default" : "Hushed voices whisper quietly in the background.",
            ]) );
   SetSmell( ([
                "default" : "Soft, displeasing odors are nearly visible in their intensity.",
           ]) );
   SetExits( ([
                "east" : PR + "/quarantine",
           ]) );
   SetInventory( ([
                    PN + "/diseased" : 4,
                    PN + "/doctor" : 2,
                    PN + "/sickkid" : 6,
               ]) );
}
