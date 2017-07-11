/* a small clearing
    kyla 2-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small clearing");
SetDomain("Valley");
  SetClimate("temperate");
  SetExits( ([
      "south" : MANSION_ROOMS + "pasture2",
      "southwest" : MANSION_ROOMS + "pasture1",
      "southeast" : MANSION_ROOMS + "pasture3",
     "east" : MANSION_ROOMS + "clearing3",
     "west" : MANSION_ROOMS + "clearing1",
       ]) );
  SetInventory( ([
     CLEARING_NPC + "white_deer" : 1,
              ]) );
  SetSmell( ([
      "default" : "The distinct smell of long grass is overwhelming.",
          ]) );
  SetListen( ([
      "default" : "Chirping birds can be heard in the distance.",
        ]) );
  SetLong("The clearing is full of long grass, though it appears that "
         "this is a favorite area for grazing. A few small bushes are "
        "scattered across the clearing which extends to the east and west. "
       "There also appears to be a pasture to the south.");
  SetItems( ([
    "clearing" : (:GetLong:),
    "grass" : "The grass is very long here.",
  ({"bush", "bushes"}) : "The few bushes that are here appear quite prickily.",
    "pasture" : "The pasture lies to the south.",
            ]) );
  }
