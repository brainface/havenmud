/* a small barn
    kyla 3-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small stall");
SetDomain("Valley");
  SetClimate("indoors");
  SetExits( ([
     "east" : MANSION_ROOMS + "barn2",
          ]) );
  SetInventory( ([
      PASTURE_NPC + "cow" : 1,
              ]) );
  SetSmell( ([
      "default" : "The scent of cow manure is overwhelming.",
          ]) );
  SetListen( ([
       "default" : "Stomping of hoofs can be heard throughout the barn.",
          ]) );
  SetLong("The small stall is covered in straw and manure, and looks as "
          "though it could use a good cleaning. Another small stall can "
          "be seen over the divider. The roof of the barn is high and "
          "supported by many rafters. In the air the dust sparkles as the "
         "sulight reflects off of it.");
  SetItems( ([
        "stall" : (:GetLong:),
        "straw" : "The dry straw covers the floor of the stall.",
        "floor" : "The floor is covered in straw and manure.",
        "manure" : "This is obviously the manure of a large animal.",
        "divider" : "The wooden divider does a good job of separating the animals.",
        "roof" : "The boards in the roof are separated just enough for "
                 "sunlight to shine through.",
    ({"board", "boards"}) : "The boards are spaced far apart.",
   ({"rafter", "rafter"}) : "The rafters suppoert the roof.",
         "air" : "The warm air is filled with dust.",
    ({"dust", "particle", "particles"}) : "The dust shimmers in the sunlight.",
       "sunlight" : "The sunlight is full of dust.",
     ]) );
  }
