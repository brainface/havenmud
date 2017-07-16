// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("a watery ledge");
   SetLong("Water from the falls to the east has made the rocks here "
           "rather damp and cold.  A few fish have strayed across "
           "as well, and flop rather pathetically in a small pool.  From "
           "here you could also walk down a fairly nice path to the lake "
           "beneath the waterfall.");
   SetItems( ([
                ({ "falls water","water" }) :
                   "The wet rocks are covered with water.",
                ({ "wet rocks","rocks","rock","wet rock" }) :
                   "The dark rock looks even darker when it's "
                   "covered in water",
                ({ "pathetic fish","fish" }) :
                   "Stranded in a small pool, the fish flop around in "
                   "a sad, dying manner.",
               ({ "small pool","pool" }) :
                   "The pool lies in a dip of the"
                   "ledge, and is not very large.",
                ({ "shallow lake","lake" }) :
                   "The lake below you lies under a waterfall.",
                ({ "nice path","path" }) :
                   "The nice path heads to the lake below.",
                ({ "east waterfall","waterfall" }) :
                   "The waterfall's spray has made the rocks "
                   "here quite wet.",
                ({ "waterfall spray","spray" }) :
                   "The water has made the rocks rather wet.",
           ]) );
   SetExits( ([
                "east" : C_ROOM + "rooms",
                "southeast" : C_ROOM + "roomt",
           ]) );
   SetInventory( ([
                    C_NPC + "trout" : 1,
                    C_NPC + "dogfish" : 3,
               ]) );
}
