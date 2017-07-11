/*  Level #2 - Cavern #2 - Section #4  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(0);
  SetShort("a small cavern");

  SetLong("This portion of the cavern contains a tunnel leading to the south "
          "and out of sight.  From the tunnel there is a light breeze blowing "
          "fresh air into the cavern.  In addition, the rock formations block "
          "your sight in every other direction.  Up on the ceiling in between "
          "stalactites a colony of bats has claimed this part of the cave as "
          "it's own.");

  SetSmell( ([
    "default"  :  "The smell of guano mixes with the ever present smell of "
                  "moist limestone rock.",
  ]) );

  SetListen( ([
    "default"  :  "The sound of high pitched squeaking and leathery flapping "
                  "wings echoes throughout the cavern.",
  ]) );

  SetExits( ([
    "north"      :  ROOMLV2 + "/cave2b",
    "northwest"  :  ROOMLV2 + "/cave2a",
    "west"       :  ROOMLV2 + "/cave2c",
    "south"      :  ROOMLV2 + "/tunnel2a",
  ]) );
  SetObviousExits("north, northwest, south, west");

  SetItems( ([
    ({ "small cavern", "cavern", "cave" })  :  (: GetLong :),
    ({ "tunnel" })  :
       "There is a tunnel that leads off to the south and exits the cavern.  "
       "A light breeze of fresh air is emanating from the tunnel.",
    ({ "rock formations", "rock formation", "formations", "formation" })  :
       "The rock formations fill the cavern and block your view of the rest "
       "of the cave and gives the cavern an ancient yet ageless quality.",
    ({ "stalactites", "stalactite", "ceiling", "colony", "colony of bats",
       "bats" })  :
       "Up on the ceiling a colony of bats has claimed it's ground for a home "
       "between the stalactites and rock formations.  Every so often a bat "
       "will fly around to a different position and a new footing.",
  ]) );

  SetInventory( ([ NPCS + "/bat" : 1, ]) );
}
