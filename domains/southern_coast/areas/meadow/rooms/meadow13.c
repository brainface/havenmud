// The bay where you can fish, and there is a store!
// For Platypus Bay
// Urien@Haven 06JUL08
// Cleaned up 03JUL13

#include <lib.h>
#include <domains.h>
#include "../meadow.h"

inherit LIB_FISHING;

static void create() {
 fishing::create();
 SetShort("a smooth sandy beach");
 SetFish( ([
          "/std/fish/guppy" : 27,
          "/std/fish/shark" : 18,
     ]) );

 SetChance(40);
 SetInventory( ([
      MEADOW_NPC  "human"  : 1,
      MEADOW_OBJ  "canoe"  : 1,
      MEADOW_NPC  "duck"   : 2,
               ]) );
 SetListen( ([
          "default" : "The crashing of the waves is all that can "
                      "be heard.",
             ]) );
 SetSmell( ([
          "default" : "The smell of the sea is strong here.",
             ]) );
 SetLong( "The grass thins to a nice sandy beach. The grains "
          "of sand are small and white covering all the way to "
          "the shore. A small staw hut stands to the north with "
          "an inviting entrance. Some straw cots have been placed "
          "along the shore for relaxing or basking in the weather."
          );
 SetItems( ([
    "path" : "A small dusty path leading to the north.",
   "grass" : "The grass gets buried under the sand torwards "
             "the coast.",
   "beach" : (:GetLong:),
 "entrance" : "There is a square cut entrance in the hut "
              "welcoming anyone to enter.",
    "cots" : "The cots are made of the exact same straw as "
             "the hut. Thin staw sewn closely together to "
             "support any weight.",
     "bay" : (:GetLong:),
     "hut" : "A small straw hut stands to the north with an "
             "inviting entrance.",
           ]) );
 SetExits( ([
   "north" : MEADOW_ROOMS  "meadow9",
   "west"  : MEADOW_ROOMS  "meadow12",
   "south" : INNERSEA_VIRTUAL "ocean/-19,0",
           ]) ); 
 SetEnters( ([
      "hut" :  MEADOW_ROOMS  "hut",
   ]) );
 SetProperty("coastal", 1);
}

