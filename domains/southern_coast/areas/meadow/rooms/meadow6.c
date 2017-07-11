/* a meadow room
   Kyla 10-16-97
*/
#include <lib.h>
#include "../meadow.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a meadow");
  SetObviousExits("north, south, east");
  SetExits( ([
           "north" : MEADOW_ROOMS + "meadow2",
            "south" : MEADOW_ROOMS + "meadow10",
           "east" : MEADOW_ROOMS + "meadow7",
          ]) );
  SetSmell( ([
           "default" : "The scent of grass overwhelms you."
           ]) );
  SetListen( ([
           "default" : "The noise of the waves is quite loud here.",
           ]) );
  SetLong("The meadow appears to continue on forever from this "
          "vantage point. The grass stretches on almost endlessly "
           "to the north and east. To the south it appears that the "
          "grass gradually gives way to the sea.");
  SetItems( ([
          "grass" : "This tall brown grass is quite tall and makes "
                     "it difficult for one to see.",
           ]) );
SetInventory( ([
           MEADOW_NPC + "kangaroo" : 2,
            ]) );
  }
