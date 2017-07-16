/* This is the fifteeth room of the beach coded by Lynna on January 28, 1998
*/

#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../beach.h"

inherit LIB_FISHING;
static void create() {

  ::create();
  SetShort("the smooth sands of the beach");
  SetSmell( ([ "default" : "The strong salty air of the sea is present."
        ]) );
  SetInventory( ([
    BEACH_NPC + "hermit" : 1,
    ]) );
  SetListen( ([ "default" : "The crashing of the waves can be heard, "
          "along with the loud, noisy seagulls." ]) );
  SetLong( "The sand here is closer to the path than the actual water. "
     "The sand is hot and smooth, and looks as if it carries on "
     "for miles. The water can be seen in the distance and looks "
     "deep, dark, and cold." );
  SetClimate("temperate");
  SetItems( ([
    ( { "sands", "beach", "sand" } ) : "The sand of the beach "
               "connects with the cold "
               "water here.",
    ( { "sea", "water", "waters" } ) : "The dark waters of the "
               "sea are rough and covered "
               "with large, white-capped "
               "waves.",
    "waves" : "These large white-capped waves cover the sea.",
    ( { "seagulls", "seagull" } ) : "These small birds fly high "
            "in the sky above.",
    ( { "birds", "bird" } ) : "These seagulls fly high above the "
            "sea.",
    ]) );
  SetExits( ([
    "south" : BEACH_ROOM "beach14",
    "west"  : BEACH_ROOM "beach16",
    "east"  : INNERSEA_VIRTUAL "ocean/12,38",
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
