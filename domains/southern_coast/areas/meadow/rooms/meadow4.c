/* a meadow room
   Kyla 10-16-97
*/
#include <lib.h>
#include "../meadow.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a meadow");
  SetObviousExits("west, south, east");
  SetExits( ([
            "west" : MEADOW_ROOMS + "meadow3",
            "east" : MEADOW_ROOMS + "meadow5",
            "south" : MEADOW_ROOMS + "meadow8",
          ]) );
  SetInventory( ([
             MEADOW_NPC + "emu" : 3,
          ]) );
  SetInventory( ([
             MEADOW_OBJ + "sign1" : 1,
               ]) );
  SetSmell( ([
           "default" : "The scent of dry grass and sea water "
                        "drifts through the air.",
          ]) );
  SetListen( ([
            "default" : "The sound of rippling grass mixes with "
                        "the ever-present crashing of waves."
            ]) );
  SetLong("To the west is the path leading north and south. "
          "Farther to the south the grass gets shorter and one "
          "could see the sea. The meadow appears to continue "
          "on to the east."
         );
  SetItems( ([
           "path" : "A small dusty path leading north and south.",
           "grass" : "Tall brown grass that appears to get shorter "
                      "as one moves south.",
           ]) );
  }
