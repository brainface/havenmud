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
  SetExits( ([
        "north" : RUINS_ROOMS + "7,-5",
        "east" : RUINS_ROOMS + "8,-6",
        "west" : RUINS_ROOMS + "6,-6",
        "south" : JUNGLE + "7,-7",
        ]) );
  SetListen( ([
       "default" : "Birds can be heard chirping in the distance.",
           ]) );
  SetSmell( ([
       "default" : "The only smell is the scent of decaying moss.",
         ]) );
  SetInventory( ([
/*
        RUINS_NPC + "python" : 1,
*/
           ]) );
  SetLong("The jungle is very thin here and one can see a path "
          "leading to the north. There appears to be what used to "
          "be a village to the north, and the jungle gets very "
          "dense to the south. A few footprints are scattered "
          "along the path.");
  SetItems( ([
        "jungle" : (:GetLong:),
        "path" : "The path leads north and is lined by the thick moss.",
       ({"footprints", "footprint"}) : "The footprints seem to have the "
                         "imprints of claws.",
       ({"imprints", "imprint"}) : "The imprints look like claws.",
        ]) );
  SetItemAdjectives( ([
         ]) );
  }
/*   [ Portia approved ] */
