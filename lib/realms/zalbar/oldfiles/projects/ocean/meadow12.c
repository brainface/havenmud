/* a fishing room
   Kyla 10-17-97
*/
#include <lib.h>
#include <domains.h>
#include "../meadow.h"
inherit LIB_FISHING;

static void create() {
  fishing::create();
  SetShort("a bay");
  SetExits( ([
           "north" : MEADOW_ROOMS + "meadow8",
           "east"  : MEADOW_ROOMS + "meadow13",
           "west"  : MEADOW_ROOMS + "meadow11",
           "south" : INNERSEA_VIRTUAL "ocean/-20, 0",
          ]) );
  SetSpeed(5);
  SetFish( ([
          "/std/fish/guppy" : 30,
          "/std/fish/shark" : 15,
     			]) );

  SetChance(40);
  SetInventory( ([
             MEADOW_NPC + "platypus" : 5,
             MEADOW_OBJ + "sign2" : 1,
               ]) );
  SetListen( ([
             "default" : "The crashing of the waves is all that can "
                          "be heard.",
             ]) );
  SetSmell( ([
             "default" : "The smell of the sea is strong here.",
             ]) );
  SetLong("To the south lies Platypus Bay, an inlet that appears to "
         "be a nice spot to fish. The meadow continues to the north "
         "and to the east. The bay continues to the west. ");
  SetItems( ([
           "path" : "A small dusty path leading to the north.",
           ]) );
  SetProperty("coastal", 1);
  }
