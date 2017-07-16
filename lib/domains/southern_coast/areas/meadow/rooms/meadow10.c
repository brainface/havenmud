/* a meadow room
   Kyla 10-16-97
*/
#include <lib.h>
#include "../meadow.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a meadow");
  SetObviousExits("north, east");
  SetExits( ([
           "north" : MEADOW_ROOMS + "meadow6",
           "east" : MEADOW_ROOMS + "meadow11",
           ]) );
  SetSmell( ([
            "default" : "The scent of the sea overwhelms you.",
         ]) );
  SetListen( ([
            "default" : "All that is heard is the thundering "
                        "crash of waves from the sea.",
           ]) );
  SetInventory( ([
              MEADOW_NPC + "dingo" : 3,
               ]) );
  SetLong("The grass thins out here as it gives way to sand. "
          "The bay is off to the west, and one can see the glimmering "
           "waves in the distance. What little grass is here "
          "is matted from the apparant constant trail of animals "
          "travelling to the bay for water.");
  SetItems( ([
           "grass" : "This grass is shorter and appears quite trampled.",
           "bay" : "A small inlet from the Ruined Sea.",
           "waves" : "The waves glimmer in the sun as they crash "
                     "against the shore.",
            ]) );
  }
