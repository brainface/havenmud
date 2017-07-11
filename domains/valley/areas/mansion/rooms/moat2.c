/* a moat
    kyla 2-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the banks of a moat");
SetDomain("Valley");
  SetClimate("temperate");
  SetExits( ([
      "north" : MANSION_ROOMS + "moat3",
      "south" : MANSION_ROOMS + "moat1",
      "west" : MANSION_ROOMS + "pasture4",
      "southwest" : MANSION_ROOMS + "pasture5",
      "northwest" : MANSION_ROOMS + "pasture3",
          ]) );
  SetInventory( ([
          ]) );
  SetSmell( ([
     "default" : "The rancid odor of the still moat water is overwhelming.",
          ]) );
  SetListen( ([
      "default" : "The cry of gulls can be heard to the north.",
          ]) );
  SetLong("The bank of the moat is all muddy and covered in animal tracks. "
          "To the west is a pasture while to the east lies a large mansion. " 
         "The moat stretches to the north and south and is quite gross due "
       "to the algae growing on its surface.");
  SetItems( ([
        "bank" : "The bank is very muddy.",
   ({ "animal tracks", "tracks" }) : "The tracks appear very birdlike.",
        "pasture" : "The pasture lies to the west.",
        "mansion" : "The mansion is across the moat.",
        "moat" : "The moat is covered in algea.",
         "algea" : "The green plant is abundant here.",
         "surface" : "The surface of the moat is covered in algea.",
           ]) );
  }
