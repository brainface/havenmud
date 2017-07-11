// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("a tight chimney");
   SetLong("The way up this tight crevice is difficult and rough, "
           "able to cut and bruise a climber's hands, while the "
           "chimney is so tight that one can hardly hope to complete the "
           "upward journey without scratching one's back, or wings, "
           "as it may be.");
   SetItems( ([
                ({ "tight chimney","tight crevice","chimney","crevice" }) :
                   "The tight, upward tunnel is rough, jagged, and "
                   "arduous to climb.",
           ]) );
   SetSmell( ([
                "default" : "The smell from above is not pleasant, "
                   "not at all.",
           ]) );
   SetListen( ([
                 "default" : "Screechings noises like those of a bat "
                    "come from above.",
            ]) );
   SetExits( ([
                "up" : C_ROOM + "roomc",
                "down" : C_ROOM + "roome",
           ]) );
   SetInventory( ([
                    C_NPC + "bigbat" : 2,
                    C_NPC + "lilbat" : 1,
               ]) );
}
