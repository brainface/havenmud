/* path leading to haven road
   kyla 10-16-97
*/
#include <lib.h>
#include "../meadow.h"
#include <domains.h>
#define HAVEN_ROAD   SOUTHERN_COAST_VIRTUAL "havenroad/11,0"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("a small path");
  SetObviousExits("north, south");
  SetExits( ([
          "north" : HAVEN_ROAD,
          "south" : MEADOW_ROOMS + "meadow3",
           ]) );
  SetSmell( ([
          "default" : "The scent of sea water is in the air.",
           ]) );
  SetListen( ([
          "default" : "You can hear waves crashing to the south."
           ]) );
  SetLong("The path leads north to Haven Road, and south to "
          "what appears to be a small bay. There is a "
          "scattering of trees and bushes surrounding the path. "
          "Many strange footprints litter the area.");
  SetItems( ([
     "path" : "A small dusty path leading north and south.",
     "bay" : "The bay appears to be a small inlet of the Ruined Sea.",
     ({ "tree", "trees" }) : "The trees appear to be very normal.",
     ({ "bush", "bushes" }) : "The bushes appear to be very normal.",
    ({ "footprint", "footprints" }) : "These are exceptionally long "
                                      "footprints.",
      ]) );
  }
