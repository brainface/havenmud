/* This is the fourteenth room of the beach coded by Lynna on January 28, 1998
*/

#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../beach.h"
inherit LIB_ROOM;
inherit LIB_FISHING;
static void create() {

  room::create();
  SetSmell( ([ "default" : "The salty smell of the sea is very "
         "strong." ]) );
  SetInventory( ([
    BEACH_NPC + "kid" : 2,
    ]) );
  SetListen( ([ "default" : "The crashing of the waves is very loud "
          "along with the noisy seagulls above." ]) );
  SetLong( "The smooth sand is hot here, and continues for miles down "
     "the shore. The sea can be seen clearly from this point on "
     "the beach.  Above, the seagulls fly in patterns, and "
     "occasionally land on the surface of the water." );
  SetShort("the smooth sands of the beach");
  SetClimate("temperate");
  SetItems( ([
    ( { "sea", "water", "waters", "surface" } ) : "The dark blue "
            "eastern sea is rough, "
            "covered with waves.",
    "waves" : "These large white-capped waves cover the sea.",
    ( { "seagulls", "seagull" } ) : "These birds fly above the "
            "sea.",
    ( { "bird", "birds" } ) : "These are the seagulls that fly "
            "high in the sky.",
    ( { "sand", "shore", "beach" } ) : "Here, the sand and the "
            "sea meet."
    ]) );
  SetExits( ([
    "south" : BEACH_ROOM "beach13",
    "north" : BEACH_ROOM "beach15",
    "east"  : INNERSEA_VIRTUAL "ocean/12,37",

    ]) );
    SetSpeed(5);
  SetFish( ([
    DIR_STD "fish/guppy" : 100,
    DIR_STD "fish/trout" : 50,
    ]) );
  SetChance(25);
  SetMaxFishing(4);
}