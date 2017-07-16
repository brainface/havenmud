/* a clearing
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
      "south" : MANSION_ROOMS + "moat6",
      "west" : MANSION_ROOMS + "clearing7",
      "southwest" : MANSION_ROOMS + "moat5",
            ]) );
  SetInventory( ([
             ]) );
  SetListen( ([
       "default" : "This part of the clearing is very quiet.",
           ]) );
  SetSmell( ([
        "default" : "There is a very bad odor coming from the south.",
           ]) );
  SetLong("The clearing is full of long grass and small bushes. "
          "a lone tree sits in the northeast corner. To the south lies "
          "what appears to be a body of water. There appear to be some "
           "small footprints in the dirt.");
  SetItems( ([
         "clearing" : (:GetLong:),
        "grass" : "The grass is long and appears very healthy.",
     ({"bush", "bushes"}) : "The bushes are short but very full.",
        "tree" : "This large tree looks very out of place.",
       "corner" : (:GetLong:),
        "water" : "The water lies to the south.",
    ({"footprint", "footprints"}) : "These are small humanoid footprints.",
         "dirt" : "The dirt appears to have some footprints in it.",
             ]) );
   }
