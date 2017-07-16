/*  Western Road
 *  Kresh Village
 */
#include <lib.h>
#include "../goblins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small alley off the main path");
  SetLong("The alley ends in a small, barren wasteland which "
         "consists of only a single tent.  The tent is small and "
         "black, which no discernable markings of any kind. To the "
         "east the path leads back to the main village path.");
  SetItems( ([
     "tent" : "The small black tent is rather unimposing.",
      ]) );
  SetInventory( ([
    GOBLIN_NPC + "valk" : random(3) + 2,
      ]) );
  SetEnters( ([
     "tent" : GOBLIN_TENT + "valkyr",
     ]) );
  SetListen( ([
     "default" : "The area is fairly quiet.",
      ]) );
  SetSmell( ([
     "default" : "The area smells rather pleasant.",
    ]) );
  SetObviousExits("east");
  SetExits( ([
    "east" : GOBLIN_ROOM + "m_2",
    ]) );
  }
