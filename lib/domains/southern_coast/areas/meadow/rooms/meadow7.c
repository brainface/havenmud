/* a meadow room
   Kyla 10-16-97
*/
#include <lib.h>
#include "../meadow.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a meadow");
  SetObviousExits("north, south, east, west");
  SetExits( ([
           "north" : MEADOW_ROOMS + "meadow3",
           "south" : MEADOW_ROOMS + "meadow11",
           "east" : MEADOW_ROOMS + "meadow8",
           "west" : MEADOW_ROOMS + "meadow6",
           ]) );
  SetSmell( ([
           "default" : "The scent of sea water mixes with the "
                        "fresh scent of long grass.",
            ]) );
  SetListen( ([
            "default" : "The waves of the Ruined Sea can be heard "
                         "to the south.",
            ]) );
  SetInventory( ([
               MEADOW_NPC + "dingo" : 1,
               ]) );
  SetLong("The path continues to stretch north and south, with " 
          "the meadow extending to the east and west as if it "
           "would never end. From here one can see the bay that "
          "lies to the south.");
  SetItems( ([
          "path" : "A small dusty path that leads north and south.",
           "bay" : "A small inlet from the Ruined Sea.",
           "grass" : "This tall grass is quite tall.",
          ]) );
  }
