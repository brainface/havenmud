#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(3);
   SetShort("inside a burial vault");
   SetLong("Rectangular cavities are lined up in the stone walls, all "
           "filled with bodies of those long dead.  An opening leads out "
           "to the east, but it is quite small and lets in little "
           "light.  On the opposite wall rests a slab of stone with "
           "cryptic writing on it.");
   SetItems( ([
                ({ "burial vault","vault" }) : (: GetLong :),
                ({ "rectangular cavities","rectangular cavity",
                   "cavity","cavities","bodies","body","holes","hole" }) :
                   "The bodies rest in a sleepless slumber, unable "
                   "to do any more.",
                ({ "stone walls","stone wall","wall","walls","opening" }) :
                   "An opening leads out of the room to the east, "
                   "the only opening in the stone walls here.  "
                   "Other than that and the holes for the dead, "
                   "the stone walls are plain and unfeatured.",
                ({ "slab of stone","slab","stone","cryptic writing",
                   "writing","ancient scrawl","scrawl" }) :
                   "The ancient scrawl written upon the stone is "
                   "indescernible, but some of it appears to have to "
                   "do with disease and death; that is, however, a "
                   "very typical choice of writing for cemetary like "
                   "areas.",
           ]) );
   SetExits( ([
                "east" : VC_ROOM + "/c_hall3",
           ]) );
   SetInventory( ([
                    VC_NPC + "/c_phant" : 1,
               ]) );
}
