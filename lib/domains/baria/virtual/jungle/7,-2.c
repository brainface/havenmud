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
     "north" : JUNGLE + "7,-1",
     "east" : RUINS_ROOMS + "8,-2",
     "west" : RUINS_ROOMS + "6,-2",
         ]) );
  SetInventory( ([
/*
       RUINS_NPC + "toucan" : 1,
       RUINS_NPC + "lizardman3" : 1,
*/
              ]) );
  SetListen( ([
     "default" : "Birds can be heard all around.",
           ]) );
  SetSmell( ([
       "default" : "The only scent is that of the decaying moss.",
         ]) );
  SetLong("The jungle comes to an abrupt stop here where it meets "
          "a large stone wall. There seems to be a small path that "
          "leads to the west, but it is mostly overgrown with moss. "
          "It doesn't appear that many people have travelled through "
          "this area lately, but the wall is indication that there once "
          "was some sort of village here.");
  SetItems( ([
       "jungle" : (:GetLong:),
       "wall" : "The large wall is covered in moss and appears to be almost "
                "ancient.",
       "path" : "The small path is barely visible through the dense moss.",
       "moss" : "The moss is very dense and a beautiful shade of green.",
       "village" : "All that can be seen of the village is this one wall.",
        ]) );
  SetItemAdjectives( ([
       "wall" : ({"large", "stone"}),
       "path" : "small",
       "moss" : ({"dense", "green" }),
       ]) );
  }

/*   [ Portia approved ] */
