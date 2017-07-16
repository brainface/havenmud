/* Portia Ruins 10-6-98
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
       "west" : "/domains/baria/virtual/jungle/3,-4",
       "north" : RUINS_ROOMS + "4,-3",
       "south" : RUINS_ROOMS + "4,-5",
        ]) );
  SetListen( ([
        "default" : "The sound of birds calling can be heard from "
                    "the trees.",
           ]) );
  SetSmell( ([
         "default" : "The air smells of foliage with a slight hint of smoke.",
         ]) );
  SetLong("While the jungle is dense to the west, it is significantly "
          "thinner here, as well as to the north and south. A large, stone "
          "wall blocks the way to the east and while it is covered in moss, "
          "one can almost make out an inscription. Although there are no "
         "obvious signs of life here now, one can tell something lived "
          "here in the past.");
  SetItems( ([
         "jungle" : (:GetLong:),
        ({"stone wall", "wall" }) : "This wall is quite large and seems "
                                 "to be very old.",
      ({"moss", "foliage", "trees"}) : "The foliage has thinned, but "
                          "there is moss everywhere.",
     ({"inscription", "writing"}) : "The inscription seems to be written "
                  "in jibberish.",
    ]) );
  SetItemAdjectives( ([
        "stone wall" : ({"large"}),
            ]) );
  SetInventory( ([
/*
       RUINS_NPC + "lizardman4" : 1,
*/
          ]) );
  }
/*   [ Portia approved ] */
