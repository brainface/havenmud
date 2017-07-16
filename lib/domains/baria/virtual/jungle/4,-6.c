/*  Portia  Ruins  10-7-98
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
       "north" : RUINS_ROOMS + "4,-5",
       "south" : JUNGLE + "4,-7",
       "west" : JUNGLE + "3,-6",
       "east" : RUINS_ROOMS + "5,-6",
     ]) );
  SetInventory( ([
/*
       RUINS_NPC + "python" : 1,
*/
             ]) );
  SetLong("The foliage is very thin here. A building can be seen off to "
         "the northwest. The only other sign of life is a small path that "
         "leads east. The path is mostly overgrown with vines and moss so "
         "it is barely visible. It appears as though the only living "
        "creatures to see this part of the jungle are the animals that live "
        "here.");
  SetItems( ([
      "foliage" : "The foliage is quite thin in this area.",
     "building" : "The building is barely visible and covered in moss.",
     "path" : "The path is covered in moss and obviously not used often.",
       "moss" : "The lush green moss covers almost everything.",
      "vines" : "These vines are covering the path making travel a little "
                "more difficult.",
       ]) );
  SetItemAdjectives( ([
       "path" : "small",
        "moss" : ({"lush", "green"}),
       ]) );
  SetSmell( ([
       "default" : "The scent of decaying moss is strong.",
          ]) );
  SetListen( ([
        "default" : "The only sound is the singing of jungle birds.",
           ]) );
  }
/*   [ Portia approved ] */
