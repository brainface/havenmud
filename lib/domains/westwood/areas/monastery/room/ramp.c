#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("on a ramp");
   
   SetLong("Brown leaves skitter across the slanted surface of the "
           "wooden ramp, blowing off in the gentle breeze that "
           "crosses through the area.  Not far above, the ramp meets "
           "up with a wooden platform, while it hits the ground "
           "gently below.  Grand deciduous trees gather close to the "
           "ramp as it makes its journey.");
   SetItems( ([
                ({ "wooden ramp","ramp","slanted surface","surface" }) :
                   (: GetLong :),
                ({ "brown leaves","brown leaf","leaf","leaves" }) :
                   "The leaves have fallen from the beautiful "
                   "trees around the ramp; blown by the wind, they "
                   "fly through the air and dash across the ramp.  "
                   "Some manage to stay still, but most are moving.",
                ({ "wooden platform","platform" }) :
                   "Above is a platform, supported partially by all "
                   "the trees.  It appears that the ramp's destination "
                   "is that platform.",
                ({ "grand deciduous trees","grand deciduous tree",
                   "grand trees","grand tree","deciduous trees",
                   "deciduous tree","trees","tree" }) :
                   "The trees waver slightly in the wind, shaking "
                   "leaves off and sending them to float in the "
                   "wind.  The trees aid in the support of the ramp "
                   "and platform.",
                ({ "ground below","ground" }) :
                   "Below, the ramp hits the ground and provides access "
                   "to it.  Leaves have fallen across much of it, making "
                   "it difficult to see, and the distance only increases "
                   "that difficulty.",
           ]) );
   SetListen( ([
                 "default" : "The trees clack together and the "
                    "leaves rustle in the breeze.",
            ]) );
   SetExits( ([
                "up"   : M_ROOM + "plat_e",
                "down" : M_ROOM + "ent",
           ]) );
   SetInventory( ([
                    M_NPC + "trav_wor" : 4,
                    M_NPC + "monk_h" : random(2),
                    M_NPC + "monk_c" : 2,
               ]) );
}