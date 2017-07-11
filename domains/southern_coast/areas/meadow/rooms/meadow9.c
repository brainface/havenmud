/* a meadow room
    Kyla 10-16-97
*/
#include <lib.h>
#include "../meadow.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a meadow");
  SetObviousExits("north, south, west");
  SetExits( ([
            "north" : MEADOW_ROOMS + "meadow5",
            "south" : MEADOW_ROOMS + "meadow13",
            "west" : MEADOW_ROOMS + "meadow8",
          ]) );
  SetSmell( ([
           "default" : "There is a faint scent of smoke "
                       "combined with the smell of the sea.",
         ]) );
  SetListen( ([
            "default" : "You hear what sounds like faint "
                        "whispering.",
           ]) );
  SetLong("This appears to have been a campsite at one time. "
          "To the north, south and west the meadow extends further "
           ". The grass here is flattened and there is a fire pit "
           "off to one side.");
  SetItems( ([
           "campsite" : "This is a well used campsite with fire pit "
                        "and matted grass for sleeping.",
           "grass" : "The grass here has been flattened due to many "
                      "nights of being slept on.",
            "fire pit" : "This fire pit has obviously been "
                         "used several nights in a row due to "
                         "the smoldering coals in the bottom.",
           "coals" : "The coals are still glowing red from last "
                      "night's fire.",
          ]) );
  SetInventory( ([
                 MEADOW_NPC + "gelfling1" : 1,
                 MEADOW_NPC + "gelfling2" : 1,
               ]) );
  }
