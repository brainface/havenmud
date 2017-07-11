/*  Portia  Ruins  10-8-98
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
       "north" : JUNGLE + "6,-1",
       "west" : RUINS_ROOMS + "5,-2",
       "east" : RUINS_ROOMS + "7,-2",
         ]) );
  SetSmell( ([
      "default" : "The area smells of decaying moss.",
             ]) );
  SetListen( ([
        "default" : "Birds can be heard in the distance.",
           ]) );
  SetInventory( ([
/*
         RUINS_NPC + "lizardman2.c" : 1,
*/
            ]) );
  SetLong("The foliage has thinned here and one can see quite a "
         "distance to the east and west. There seems to be some "
         "sort of building to the south. Though the trees are thin "
        "there doesn't seem to have been much activity here in a while. "
        "A few scattered footprints are around, but there isn't much else "
       "here.");
  SetItems( ([
         "jungle" : (:GetLong:),
        ({"footprints", "footprint"}) : "These footprints are rather "
                                         "large.",
        ({"foliage", "trees"}) : "The trees and various other foliage "
                                 "are thin here.",
         ({"building", "wall"}) : "This stone building blocks to the south "  
                      "and faces the opposite direction. All that can "
                      "be seen is the back wall.",
         ]) );
  SetItemAdjectives( ([
       "footprints" : ({"large", "scattered"}),
       "building" : "stone",
           ]) );
  }
/*   [ Portia approved ] */
