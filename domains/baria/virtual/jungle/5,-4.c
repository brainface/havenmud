/* Portia Ruins  10-9-98
   A walkway through the village.
*/

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetShort("a dusty walkway");
  SetClimate("tropical");
  SetExits( ([
        "north" : RUINS_ROOMS + "5,-3",
        "south" : RUINS_ROOMS + "5,-5",
         ]) );
  SetSmell( ([
       "default" : "The area smells a bit like smoke.",
         ]) );
  SetListen( ([
      "default" : "The sound of clawed feet comes from the south.",
           ]) );
  SetInventory( ([
/*
        RUINS_NPC + "python" : 1,
*/
            ]) );
  SetLong("The walkway continues from here to the north and "
          "south. To the east lies an enormous stone and to the "
          "west lies the remnants of a building of some sort. "
          "The jungle can be seen far to the south as well as far "
          "to the north. Some scattered moss is visible but there "
          "is much less here than in the jungle.");
  SetItems( ([
      "walkway" : (:GetLong:),
      ({"enormous stone", "stone"}) : "The stone blocks the way to "
                                 "the east.",
       ({"building", "remnants"}) : "What of left of this building "
                                "looks stable enough to explore.",
        "jungle" : "The jungle is far to the north and the south.",
        "moss" : "The moss is far less abundant here than in the jungle.",
            ]) );
  SetItemAdjectives( ([
       "moss" : "scattered",
           ]) );
  SetEnters( ([
       "building" : RUINS_ROOMS + "house2", 
         ]) );
  }
/*   [ Portia Approved ] */
