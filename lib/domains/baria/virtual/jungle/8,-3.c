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
       "east" : JUNGLE + "9,-3",
       "north" : RUINS_ROOMS + "8,-2",
       "south" : RUINS_ROOMS + "8,-4",
         ]) );
  SetSmell( ([
      "default" : "The only smell is that of decaying moss.",
        ]) );
  SetListen( ([
       "default" : "Birds can be heard in the distance.",
          ]) );
  SetInventory( ([
/*
        RUINS_NPC + "lizardman1" : 1,
*/
            ]) );
  SetLong("The jungle foliage is very thin here, and it appears "
         "to have been cut away on purpose quite some time ago. "
         "A path leads to the north and south, while the jungle "
         "becomes very thick to the east. To the west a large wall "
       "blocks the way and a small wisp of smoke can be seen above "
      "it.");
  SetItems( ([
         "jungle" : (:GetLong:),
         "foliage" : "The foliage is very thin here.",
        "moss" : "The moss covers the path almost completly.",
        "path" : "The path runs north and south and is covered in moss.",
        ({"wisp", "smoke"}) : "The smoke is rising just above the wall.",
          ]) );
  SetItemAdjectives( ([
         "smoke" : "wisp of",
       "foliage"  : "thin",
       "wall" : ({"large", "stone"}),
         ]) );
  }
/*   [ Portia approved ] */
