// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../cave.h"
 
static void create() {
   room::create();
   SetClimate("underground");
   SetAmbientLight(15);
   SetShort("a dusty cavern");
   SetLong("Tunnels from the west, northeast, and south meld together to "
           "form a small cavern here.  The cave is dusty here, but not as "
           "warm as some of the other tunnels.  The cavern continues to "
           "the south.");
   SetItems( ([
                ({ "small cavern","cavern","cave" }) :
                   "Dust powders the cave.",
                ({ "cavern dust","dust" }) :
                   "The dust is fine and powdery, stirred at the "
                   "slightest movement.",
                ({ "west tunnel","tunnel","area","warmer area" }) :
                  "The west tunnel goes to a warmer area.",
                ({ "northeast tunnel","tunnel" }) :
                   "The northeast tunnel climbs upward.",
                ({ "south tunnel","tunnel" }) :
                   "The south tunnel joins the cavern to the "
                   "south.",
                ({ "south cavern","cavern" }) :
                   "The south cavern is just an extension of this one.",
                 ({ "three tunnels","tunnels" }) :
                    "Three tunnels meld together here, forming a small cavern.",
           ]) );
   SetExits( ([
                "west" : C_ROOM + "roomi",
                "south" : C_ROOM + "roomk",
                "northeast" : C_ROOM + "roome",
           ]) );
   SetInventory( ([
                    C_NPC + "spider" : 2
               ]) );
}
