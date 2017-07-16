/*  Portia  Ruins  10-9-98
      A jungle border room.
*/

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a sweltering jungle");
  SetClimate("tropical");
  SetInventory( ([
/*
            RUINS_NPC + "ape" : 1,
            RUINS_NPC + "lizardman4" : 1,
*/
               ]) );
  SetListen( ([
          "default" : "The sound of tropical birds can be heard.",
          ]) );
  SetExits( ([
       "north" : JUNGLE + "8,-1",
         "east" : JUNGLE + "9,-2",
         "west" : RUINS_ROOMS + "7,-2",
         "south" : RUINS_ROOMS + "8,-3",
           ]) );
  SetSmell( ([
        "default" : "The faint scent of smoke is in the air.",
           ]) );
  SetLong("The jungle is thin here, and stays thin off to the west. "
         "To the south there lies a small path and what seems to be a "
       "small village. Although the jungle is thin here it is much more "
       "dense to the east and north. Although a few footprints mark the "
      "path, it does not seem as if anyone has been here very recently.");
  SetItems( ([
        "jungle" : (:GetLong:),
        "path" : "The path is small and covered in moss.",
         "moss" : "This lush green moss covers the path.",
         "village" : "What appears to be a village lies to the south.",
       ({"footprints", "footprint"}) : 
                   "These footprints seem rather fresh.",
         ]) );
  SetItemAdjectives( ([
          "path" : "small",
         "moss" : ({"lush", "green"}),
         "village" : "small",
         "footprints" : "fresh",
            ]) );
  }
/*   [ Portia approved ] */
