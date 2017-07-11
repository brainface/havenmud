/* a meadow room
   Kyla 10-16-97
*/
#include <lib.h>
#include "../meadow.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a grassy meadow");
  SetObviousExits("south, east");
  SetExits( ([
             "south" : MEADOW_ROOMS + "meadow6",
             "east" : MEADOW_ROOMS + "meadow3",
          ]) );
  SetInventory( ([
                MEADOW_NPC + "dingo" : 2,
             ]) );
  SetSmell( ([
              "default" : "The strong scent of grass and weeds " 
                            "surrounds you.",
           ]) );
  SetListen( ([
               "default" : "The soft sound of rippling grass "
			   "mixes with the faint crashing of "
                          "waves in the distance.",
            ]) );
  SetLong("To the east lies the path, barely visible beyond "
          "the tall grass. The meadow seems to continue farther "
          "to the south where the grass appears to become shorter.");
  SetItems( ([
           "path" : "A dusty path leading north and south.",
           "grass" : "The tall brown grass waves in the gentle breeze.",
          ]) );
  }
