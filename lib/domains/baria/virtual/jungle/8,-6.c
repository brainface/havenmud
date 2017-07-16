/* Portia  Ruins  10-9-98
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
      "north" : RUINS_ROOMS + "8,-5",
      "west" : RUINS_ROOMS + "7,-6",
      "east" : JUNGLE + "9,-6",
      "south" : JUNGLE + "8,-7",
          ]) );
  SetListen( ([
     "default" : "The seems to be birds all around.",
          ]) );
  SetSmell( ([
     "default" : "The only smell is that of decaying moss.",
          ]) );
  SetInventory( ([
/*
       RUINS_NPC + "ape" : 1,
       RUINS_NPC + "python" : 1,
*/
          ]) );
  SetLong("This area of the jungle has been cut back tremendously "
          "and the thinness continues to the north as well as to the "
          "west. Though it is barely visible a small path seems to lead "
          "west from here, and what looks to be a building can be seen "
          "in that direction also. To the east and south the jungle is "
          "very thick.");
  SetItems( ([
       ({"area", "jungle"}) : (:GetLong:),
        "path" : "The path leads west and is covered in moss.",
        "moss" : "The moss is very thick and covers the small path.",
        ({"building", "structure"}) : "The building appears to be a very "
                                 "old structure.",
        ]) );
  SetItemAdjectives( ([
        "jungle" : "thick",
         "path" :"small",
         "moss" : "thick",
         "building" : "old",
           ]) );
  }
/*   [ Portia approved ] */
