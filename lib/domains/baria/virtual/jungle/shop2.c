/* Portia  Ruins  10-9-98
  A shopto be entered from "6,-3.c"
*/

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetShort("a small shop");
  SetClimate("tropical");
  SetExits( ([
       "out" : RUINS_ROOMS + "6,-3.c",
         ]) );
  SetSmell( ([
        "default" : "The building smells of decaying leather.",
          ]) );
  SetListen( ([
        "default" : "Footsteps can be heard.",
           ]) );
  SetInventory( ([
/*
        RUINS_NPC + "lizardman4" : 1,
*/
            ]) );
  SetLong("There is a great amount of decaying leather here. "
          "None of it is usefull but the large quantity of it "
          "indicates that this may have been a shop specializing "
          "in leather goods. Though there is no ceiling the three "
         "walls that were left from the attack seem very sturdy.");
  SetItems( ([
        ({"building", "shop"}) : (:GetLong:),
       ({"leather", "amounts", "amount", "quantity" }) : "The leather "
                        "is mostly decayed and completely worthless.",
        ({"walls", "wall"}) : "The remaining three walls seem strong.",
              ]) );
  SetItemAdjectives( ([
         "walls" : ({"three", "sturdy", "strong"}),
        ]) );
  }
/*   [ Portia Approved ] */
