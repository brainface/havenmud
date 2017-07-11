/* a dark wood
   Ela 8/3/98
*/


#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a dark wood");
  SetDomain("FrostMarches");
  SetClimate("temperate");
  SetObviousExits("southwest, south, southeast");
  SetExits( ([
     "southeast" : WOOD_ROOMS + "wood8",
    "southwest" : WOOD_ROOMS + "wood6",
    "south" : WOOD_ROOMS + "wood7",
      ]) );
  SetLong("The menacing atmosphere of the wood is stifling. "
         "Shades of darkness blanket the area. The oversized "
        "trees appear alive and threatening. Wicked briars "
        "and tangled brush litter the ground. To the east, "
        "the mouth of a cave can be seen. Dense blackness "
       "radiates unwelcomingly from deep within.");
  SetItems( ([
       ({"briar","briars"}) : "Wickedly sharp briars grow "
                              "everywhere in the wood. They "
                              "form dense patches making travel"
                              " difficult.",
       ({"brush"}) : "Dense brush makes travel difficult.",
        ({"massive tree","tree","trees"}) : "Massive trees appear "
            "monster-like with outstretched, clawing hands.",
        ({"sharp branch","branch","branches","hand","hands","claw"
             ,"claws"}) : "The sharp branches of the trees look "
             "like claws in the dark.",
        ({"dense blackness","blackness","darkness","atmosphere"}) : 
             "The impenatrable darkness forbodes danger.",
        ({"rocky opening","opening","mouth"}) : "A rocky opening "
             "dominates the area.",
        ({"large cave","cave"}) : "The rocky cave is intimidating " 
             "and shrouded with darkness.",
        ]) );
  SetEnters( ([
        ({"cave"}) : WOOD_ROOMS + "wood9",
        ]) );
  SetListen( ([
        "default" : "An eery, unnatural silence hovers here.",
        ]) );
  SetInventory( ([
         WOOD_OBJ + "sign" : 1,
        ]) );

}
