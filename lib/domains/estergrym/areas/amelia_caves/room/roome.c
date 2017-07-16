// Amelia@Haven


#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("a thinning passageway");
   SetLong("The upward passage turns into a tight chimney above, and "
           "the rock walls seem to become more jagged and rough.  The "
           "dust which seemed so prevalent below is now mostly gone.");
   SetItems( ([
                ({ "upward passage","passage" }) :
                   "As the passageway gets smaller, the tunnel slants to "
                   "face almost straight up, forming a tight chimney.",
                ({ "tight chimney","chimney" }) :
                   "The rocks become more jagged in the tight chimney.",
                ({ "rock walls","rock wall","wall","walls" }) :
                   "Jagged rocks protrude from the wall.",
                ({ "jagged rocks","rock","rocks","jagged rock" }) :
                   "Jutting out from the wall, the jagged rocks provide "
                   "handholds for those who must climb up.",
                ({ "passage dust","dust" }) :
                   "The fine, powdery dust is almost all gone.",
                ({ "thinning passageway","passageway" }) :
                   "The passageway thins above.",
                ({ "smelly tunnel","tunnel" }) :
                   "The tunnel thins above.",
           ]) );
   SetSmell( ([
                "default" : "The tunnel seems to have a strange, "
                   "animal-like smell coming from the upward exit.",
           ]) );
   SetListen( ([
                 "default" : "Faint screeching noises come from "
                    "above, as well as the light flapping sound of "
                    "wings.",
            ]) );
   SetExits( ([
                "southwest" : C_ROOM + "roomj",
                "up" : C_ROOM + "roomg",
           ]) );
   SetInventory( ([
                    C_NPC + "lilbat" : 1,
                    C_NPC + "spider" : 2,
               ]) );
}
