#include <lib.h>
#include "/domains/havenwood/towns/parva/parva.h"
#include "/domains/havenwood/areas/assassin_hall/assassin_hall.h"

inherit LIB_ROOM;

static void create() {
   ::create();
   SetTown("Parva");
   SetAmbientLight(30);
   SetShort("under the docks");
   SetLong("Lengths of partially submerged boards lead westward towards "
                  "solid land and a dank hole in the wharf wall. A small "
                  "series of carefully positioned boards leads back up to the docks. "
                  "Large and small vessels alike can be seen docking "
                  "and departing from here up and down the wharf.");
   SetItems( ([
                ({ "boards","submerged boards" }) :
                   "The wooden boards are nothing special; "
                   "They are rough and damaged.",
                ({ "vessels", "ships"}) : "The ships unload their cargo and make "
                    "their way further down the coast."
                 ]) );

   SetListen( ([
                 "default" : "The sea laps noisily against the boards, above "
                 "the scratches and thumps of the docks can be heard "
                 "through thin planking."
            ]) );
   SetSmell("Saltwater and dead fish seem to be the prominent smells under the docks.");
   SetExits( ([
     "west" : AH_ROOM "assassin_guildhall",
     "up"   : PARVA_ROOM  "docks1",
     ]) );
}
