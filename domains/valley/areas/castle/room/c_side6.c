#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(5);
   SetShort("inside a burial vault");
   SetLong("Curtains of metal mesh hang over the small niches in the "
           "walls.  Inside them, corpses wait pensively to complete "
           "their decomposition.  An opening in the stone walls leads "
           "out to the west, and light seeps in from that direction, "
           "though very little.");
   SetItems( ([
                ({ "stone walls","stone wall","walls","walls",
                   "opening" }) :
                   "The opening to the west lets in some small amount "
                   "of light.  Niches in the walls make room for the "
                   "bodies of the dead.  Other than that, however, the "
                   "walls are bare of feature.",
                ({ "burial vault","vault","room" }) :
                   (: GetLong :),
                ({ "small niches","small niche","niche","niches",
                   "metal mesh","mesh","metal","curtains","curtain",
                   "corpses","corpse" }) :
                   "The corpses peacefully decay, and these do "
                   "appear to have been decomposing for a while "
                   "behind their curtains of metal inside their "
                   "niches in the walls.",
           ]) );
   SetExits( ([
                "west" : VC_ROOM + "/c_hall3",
           ]) );
   SetInventory( ([
                    VC_NPC + "/c_ghost" : 1,
                    VC_NPC + "/c_spook" : 2,
               ]) );
}
