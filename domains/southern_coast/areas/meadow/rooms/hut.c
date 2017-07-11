// A straw store! Boo Yea!
// For Platypus Bay
// Urien@Haven 06JUL08
// Updated Urien@Haven 03JUL13

#include <lib.h>
#include <domains.h>
#include "../meadow.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside a straw hut");
  SetClimate("indoors");
  SetAmbientLight(50); 
  SetInventory( ([
                    MEADOW_NPC "gelfling"  : 1,
                 ]) );
  SetListen( ([
     "default" : "A slight whistle is heard as the wind blows "
                 "through the straw walls.",
             ]) );
  SetSmell( ([
     "default" : "It smells strong of raw seafood.",
             ]) );
  SetLong(
          "Inside of the straw hut is rather plain. A straw "
          "counter has been placed with numerous buckets which "
          "contain some smelly bait. Some crude looking fishing "
          "poles line the eastern wall tied tightly by some strong "
          "twine. The ceiling cones up to a point with the outside "
          "weather breaking in slightly."
          );
  SetItems( ([
 "counter" : "The square counter is made of straw, and probably couldn't "
             "support much.",
     "hut" : (:GetLong:),
 "buckets" : "The clear white buckets are round, and contain bait.",
    "bait" : "The bait comes in various shapes and forms. It is difficult "
             "to see due to them being behind the counter.",
   "poles" : "The fishing poles are tied to the east wall and appear to "
             "have been made in haste. They are of poor quality.",
   "twine" : "The twine is thick and coated in wax to enhance strength.",
 "ceiling" : "The ceiling is made of straw and cones up to a point in "
                       "the middle.",
           ]) ); 
  SetExits( ([
          "out" :  MEADOW_ROOMS "meadow13",
           ]) );        
}