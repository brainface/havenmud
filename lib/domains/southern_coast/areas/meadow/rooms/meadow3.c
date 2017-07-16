/* room in the meadow
   kyla 10-16-97
*/
#include <lib.h>
#include "../meadow.h"
inherit LIB_ROOM;


static void create() {
  room::create();
  SetShort("a meadow");
  SetObviousExits("north, south, east, west");
  SetExits( ([
              "north" : MEADOW_ROOMS + "path1",
              "south" : MEADOW_ROOMS + "meadow7",
              "east" : MEADOW_ROOMS + "meadow4",
              "west" : MEADOW_ROOMS + "meadow2",
             ]) );
  SetInventory( ([
          MEADOW_NPC + "groundhog" : 4,
               ]) );
  SetSmell( ([
              "default" : "The scent of long grass and sea water "
                          "fills your senses."
               ]) );
  SetListen( ([ 
               "default" : "Animal noises are heard in the distance."
         ]) );
  SetLong("The trees have thinned here, and the path continues "
          "to the north and south. To the east and west to meadow "
          "seems to stretch indefinitely. Now the long footprints "
          "have begun to mix with some more familiar types.");
  SetItems( ([
             ({"tree", "trees" }) : "The trees that are here "
                                   "seem very normal.",
             "path" : "A small dusty path leading north and south",
            ({"footprint", "footprints" }) : "An unidentifiable"
                                              " mixture of differant "
                                             "types of footprints."
	]) );
  }
