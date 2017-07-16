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
           "north" : MEADOW_ROOMS + "meadow7",
           "east"  : MEADOW_ROOMS + "meadow12",
           "west"  : MEADOW_ROOMS + "meadow10",
           "south" : INNERSEA_VIRTUAL "ocean/-21,0",
          ]) );
  SetSpeed(5);
  SetFish( ([
          "/std/fish/guppy" : 68,
          "/std/fish/shark" : 18,
          "/std/fish/boot" : 1,
     ]) );

  SetChance(40);
  SetInventory( ([
             MEADOW_NPC + "platypus" : 5,
             MEADOW_NPC + "fisher"   : 1,
               ]) );
  SetListen( ([
             "default" : "The crashing of the waves is all that can "
                          "be heard.",
             ]) );
  SetSmell( ([
             "default" : "The smell of the sea is strong here.",
             ]) );
  SetLong("To the south lies Platypus Bay, an inlet that appears to "
          "be a nice spot to fish. The path leads back to the north "
           "towards Haven Road. The bay continues to the east, while "
          "to the west lies the meadow.");
  SetItems( ([
           "path" : "A small dusty path leading to the north.",
          "bay" : (:GetLong:),
           ]) );
  SetProperty("coastal", 1);
  }
