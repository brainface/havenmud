// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("a bat cave");
   SetLong("Scattered piles of guano lay strewn around this bat "
           "cave.  A tight chimney heads downward.");
   SetItems( ([
                ({ "scattered pile","pile of guano","guano","piles",
                   "piles of guano" }) :
                   "The piles of guana scattered about this cave "
                   "smell rather badly.",
                ({ "bat cave","cave" }) :
                   "Guano and bats are about all this cave has to offer "
                   "to sight-seers.",
                ({ "tight chimney","chimney" }) :
                   "This seems to be the only way out.",
           ]) );
   SetSmell( ([
                "default" : "Smells of guano and dirty bats fill the air.",
                ({ "guano piles","guano" }) :
                   "One whiff should be enough to convince anyone to "
                   "leave--and soon!",
           ]) );
   SetExits( ([
                "down" : C_ROOM + "roomg",
           ]) );
   SetInventory( ([
                    C_NPC + "lilbat" : 5,
               ]) );
}
