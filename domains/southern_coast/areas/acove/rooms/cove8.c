/*ship5
 zara 8/1/98
*/

#include <lib.h>
#include "../acove.h"
inherit LIB_ROOM;

static void create() {
 room::create();
SetShort("a pirate galleon");
 SetClimate("temperate");
 SetExits( ([
        "east" : ACOVE_ROOMS + "cove7",
       "down" : ACOVE_ROOMS + "cove13",
         ]) );
SetLong("Resting atop the prow of the ship, smiling invitingly, "
        "is a buxom beauty. Upon closer examination of the "
        "fetching maiden, however, one can see that she "
        "is made of wood and there is only half of her at "
        "that! She must have been dislodged when the ship "
       "ran aground and ended up in her present position.");
  SetItems( ([
      ({"prow","ship"}) : "The view of the beach from this part "
                          "of the ship is beautiful.",
     ({"wooden beauty","maiden","beauty"}) : "This beautifully carved figurehead "
               "is in good condition."

                              
     ]) );
  SetItemAdjectives( ([
     "beauty" : ({"buxom","wooden"})
  ]) );
  SetInventory( ([
     ACOVE_NPC + "lucie" : 1,
     ]) );
}
