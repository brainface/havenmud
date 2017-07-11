/* Portia  Ruins  10-6-98
    Jungle border room
*/

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a sweltering jungle");
  SetClimate("tropical");
  SetExits( ([
       "north" : RUINS_ROOMS + "4,-4",
       "south" : RUINS_ROOMS + "4,-6",
       "west" : JUNGLE + "3,-5",
          ]) );
  SetSmell( ([
       "default" : "The scent of smoke is barely detectable.",
        ]) );
  SetListen( ([
       "default" : "Chirping birds are all that can be heard."
         ]) );
  SetInventory( ([
/*
      RUINS_NPC + "toucan" : 1,
*/
         ]) );
  SetLong("The jungle has become quite thin here, as well as to the "
          "north and the south. There is what seems to be a large "
         "building to the east preventing passage in that direction. "
        "Though it is apparant that there once was a civilization of "
        "some sort here, it does not seem that there are any signs of "
         "life now.");
  SetItems( ([
      "jungle" : (:GetLong:),
     ({"large building", "building" }) : "This building prevents passage "
                            "to the east.",
            ]) );
  SetItemAdjectives( ([
             ]) );
  }
/*   [ Portia approved ] */
