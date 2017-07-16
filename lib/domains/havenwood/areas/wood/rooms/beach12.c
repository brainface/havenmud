/* This is the twelfth room of the beach coded by Lynna on January 28, 1998
*/

#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../beach.h"

inherit LIB_FISHING;

static void create() {

  ::create();
  SetShort("the dropoff to the sea");
  SetClimate("temperate");
  SetSmell( ([ "default" : "The smell of salt is very strong "
         "while standing in this water." ]) );
  SetInventory( ([
    BEACH_NPC + "seagull" : 2,
    BEACH_NPC + "fish"    : 1,
    ]) );
  SetListen( ([ "default" : "The crashing of the waves along the shore "
          "can be heard in the distance." ]) );
  SetLong( "While standing out past the shore, the depths of the sea "
     "can be seen while peering straight down into the cold "
     "waters. This cliff holds solid, but is rather close to the "
     "dropoff into the sea.");
  SetItems( ([
    ( { "dropoff", "cliff" } ) : "This is the edge of the cliff "
               "of the shallow waters.",
    ( { "sea", "waters", "water" } ) : "The rough waters of the "
               "sea are a deep blue.",
    "salt" : "The salt is not visible in the water.",
    "waves" : "These large white waves cover the sea.",
    "shore" : "This is the edge of the sandy beach and the "
        "water.",
    ( { "sandy beach", "beach" } ) : "The sand and the sea go "
             "on for miles.",
    ]) );
  SetExits( ([
    "southwest" : BEACH_ROOM "beach11",
    "north"     : BEACH_ROOM "beach13",
    "south"     : INNERSEA_VIRTUAL "ocean/11,34",
    "southeast" : INNERSEA_VIRTUAL "ocean/12,34",
    "east"      : INNERSEA_VIRTUAL "ocean/12,35",
    ]) );
  SetSpeed(5);
  SetFish( ([
    DIR_STD "fish/guppy" : 100,
    DIR_STD "fish/trout" : 50,
    DIR_STD "fish/boot" : 1,
    ]) );
  SetChance(25);
  SetMaxFishing(4);
}
