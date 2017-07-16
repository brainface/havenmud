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
  SetInventory( ([
       CLEARING_NPC + "moose" : 1,
              ]) );
  SetExits( ([
        "south" : MANSION_ROOMS + "pasture3",
        "east" : MANSION_ROOMS + "clearing4",
        "west" : MANSION_ROOMS + "clearing2",
        "southwest" : MANSION_ROOMS + "pasture2",
        "southeast" : MANSION_ROOMS + "moat3",
           ]) );
  SetSmell( ([
        "default" : "The scent of the long grass is strong here.",
          ]) );
  SetListen( ([
        "default" : "The chirping of birds mixes with the sound of dogs in "
                    "the distance.",
           ]) );
  SetLong("Long grass covers the clearing and covers the small holes that "
         "speckle the ground. The clearing extends to the east and to the "
       "south lies a pasture. A few bushes are scattered through the area.");
  SetItems( ([
       "clearing" : (:GetLong:),
      "holes" : "These holes appear to belong to some kind of rodent.",
       "pasture" : "The pasture lies to the south.",
    ({"bush", "bushes"}) : "The bushes here appear quite prickly.",
       ]) );
  }
