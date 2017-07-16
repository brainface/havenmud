/*  Portia Ruins  10-8-98
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
       "north" : RUINS_ROOMS + "5,-5",
       "south" : JUNGLE + "5,-7",
       "east" : RUINS_ROOMS + "6,-6",
       "west" : RUINS_ROOMS + "4,-6",
            ]) );
  SetSmell( ([
         "default" : "The air smells of smoke.",
           ]) );
  SetListen( ([
        "default" : "The chirping of birds is all that can be heard.",
           ]) );
  SetInventory( ([
/*
        RUINS_NPC + "toucan" : 1,
        RUINS_NPC + "lizardman2.c" : 1,
*/
        ]) );
  SetLong("The jungle is actually very thin here, and one can clearly "
          "see a path leading north into what looks like the remains of "
          "a village. From here one can see the remains of several buildings "
          "that look almost ancient. The jungle gets very dense to the south "
          "but remains thin to the east and west as though someone cleared "
          "it on purpose.");
  SetItems( ([
         "jungle" : (:GetLong:),
        "path" : "This path leads north and is rather well-defined.",
       ({"buildings", "building", "village", "remains"}) : "What is left of "
                    "the village is mostly piled on the ground.",
          "ground" : "The ground is covered in moss.",
          "moss" : "This green moss lines the path.",
          ]) );
  SetItemAdjectives( ([
          ]) );
  }
/*   [ Portia approved ] */
