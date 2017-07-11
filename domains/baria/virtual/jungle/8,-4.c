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
        "north" : RUINS_ROOMS + "8,-3",
        "south" : RUINS_ROOMS + "8,-5",
        "east" : JUNGLE + "9,-4",
         ]) );
  SetSmell( ([
       "default" : "The scent of decaying moss is abundant.",
           ]) );
  SetListen( ([
       "default" : "All other noises are drowned out by that of the "
                  "singing birds.",
         ]) );
/*
  SetInventory( ([
        RUINS_NPC + "lizardman3.c" : 1,
         ]) );
*/
  SetLong("The jungle is very thin here, and it continues that way for "
          "quite a distance to the north and south while becoming more "
          "dense to the east. A large stone wall blocks the way to the "
          "west very effectively. There is a small path that, although "
        "covered almost entirely in moss, leads to the north and the "
        "south.");
  SetItems( ([
        "jungle" : (:GetLong:),
      "wall" : "The large wall looks to be almost ancient.",
     "moss" : "The moss almost entirely covers the path.",
      "path" : "The path leads north and south and is barely visible "
               "through the moss.",
           ]) );
  SetItemAdjectives( ([
          "wall" : ({"large", " stone"}),
           "path" : "small",
            ]) );
  }
/*   [ Portia approved ] */
