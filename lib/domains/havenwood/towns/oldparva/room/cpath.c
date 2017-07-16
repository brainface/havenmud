#include <lib.h>
#include "parva.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Parva");
   SetShort("in Parva");
   SetDomain("HavenWood");
   SetLong("This path goes south to the Parva Cemetery.  "
           "To the north is the scraggly main road that "
           "goes through all of the town.  To the west is "
           "the town hall, and to the east is a store.  Neither "
           "appear to be enterable from this side.");
   SetItems( ([
                ({ "town path","path","parva","town" }) :
                   (: GetLong :),
                ({ "Parva Cemetery","cemetery" }) :
                   "The Parva Cemetery is just south of "
                   "here; this little path leads toward "
                   "it.",
                ({ "scraggly main road","road" }) :
                   "The road north of here runs east and "
                   "west through all of Parva.",
                ({ "Parva Town Hall","hall","townhall" }) :
                   "The Parva Town Hall is to the west.  "
                   "There is no entrance on this side.",
                ({ "Pons Store","pons","store" }) :
                   "Pons' Store is to the east.  There is "
                   "no entrance on this side.",
           ]) );
   SetItemAdjectives( ([ 
                         "cemetery" : ({ "parva" }),
                         "path" : ({ "town","parva" }),
                         "store" : ({ "store of","pons" }),
                         "hall" : ({ "town","parva" }),
                         "road" : ({ "main","scraggly" }),
                    ]) );
   SetListen( ([
                 "default" : "Shuffling noises come from the "
                    "north.",
            ]) );
   SetSmell( ([
                "default" : "Fish smells fill the town.",
           ]) );
   SetExits( ([
                "north" : P_ROOM + "/path2",
                "south" : P_ROOM + "/cemetery",
           ]) );
}
