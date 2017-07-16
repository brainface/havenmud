/*  Portia  Ruins 10-8-98
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
         "east" : RUINS_ROOMS + "7,-6",
         "west" : RUINS_ROOMS + "5,-6",
         "south" : JUNGLE + "6,-7",
        "north" : RUINS_ROOMS + "6,-5",
        ]) );
  SetListen( ([
       "default" : "All that can be heard are some birds singing.",
         ]) );
  SetSmell( ([
       "default" : "The only scent is that of the moss.",
         ]) );
  SetInventory( ([
/*
       RUINS_NPC + "ape" : 1,
       RUINS_NPC + "lizardman1" : 1,
*/
          ]) );
  SetLong("The jungle thins out and then comes to an abrupt stop here. "
        "To the west and east the jungle remains thin and there appears to "
       "be a small path that leads in both directions. It doesn't seem "
      "that anyone has been here in quite some time.");
  SetItems( ([
        "jungle" : (:GetLong:),
      ({"large wall", "wall" }) : "The wall is very large, and very old.",
      "moss" : "The moss is covering everything.",
       "path" : "The path is covered in moss and leads east and west.",
       ]) );
  SetItemAdjectives( ([
        "large wall" : "old",
        ]) );
  }
/*   [ Portia approved ] */
