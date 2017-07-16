/* a small clearing
   kyla 2-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a clearing");
SetDomain("Valley");
  SetClimate("temperate");
  SetExits( ([
       "west" : MANSION_ROOMS + "clearing4",
       "east" : MANSION_ROOMS + "clearing6",
       "south" : MANSION_ROOMS + "moat4",
       "southwest" : MANSION_ROOMS + "moat3",
            ]) );
  SetInventory( ([
        CLEARING_NPC + "hummingbird" : 1,
               ]) );
  SetListen( ([
       "default" : "Barking dogs can be heard in the distance.",
           ]) );
  SetSmell( ([
        "default" : "A foul odor comes from the south.",
           ]) );
  SetLong("The area is completely covered in long grass except for the "
          "small path that runs east and west. There appears to be some "
          "sort of water source to the south and the clearing extends to "
          "the east and west.");
  SetItems( ([
    ({"area", "clearing"}) : (:GetLong:),
         "grass" : "The long grass has been bleached by the sun.",
         "path" : "The path runs east and west from here.",
          "water" : "The water lies to the south.",
           ]) );
  }
