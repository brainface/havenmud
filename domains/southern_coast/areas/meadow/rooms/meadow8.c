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
           "north" : MEADOW_ROOMS + "meadow4",
           "south" : MEADOW_ROOMS + "meadow12",
           "west" : MEADOW_ROOMS + "meadow7",
           "east" : MEADOW_ROOMS + "meadow9",
          ]) );
  SetSmell( ([
           "default" : "The scent of the sea is very strong here.",
          ]) );
  SetListen( ([
           "default" : "The waves of the Ruined Sea can be heard "
                       "from here.",
             ]) );
  SetInventory( ([
               MEADOW_NPC + "platypus" : 1,
              ]) );
  SetLong("The meadow extends farther to the east from here, "
           "and to the west is the path. the meadow also "
          "continues to the north and to the south lies the "
           "bay and the Ruined Sea.");
  SetItems( ([
           "path" : "A dusty path that leads north and south.",
           "bay" : "A small inlet from the ruined sea.",
           "sea" : "A large body of water on the south coast of Kailie.",
            ]) );
}
