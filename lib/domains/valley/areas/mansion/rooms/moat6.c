/* a moat
  kyla 2-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the bank of a moat");
SetDomain("Valley");
  SetClimate("temperate");
  SetInventory( ([
             ]) );
  SetExits( ([
         "north" : MANSION_ROOMS + "clearing8",
         "west" : MANSION_ROOMS + "moat5",
         "northwest" : MANSION_ROOMS + "clearing7",
              ]) );
  SetListen( ([
         "default" : "Some loud noises can be heard coming from the mansion "
                     "across the moat.",
           ]) );
  SetSmell( ([
         "default" : "The stench of the stagnant water is overwhelming.",
           ]) );
  SetLong("The bank is very muddy here and there are many footprints leading "
          "to the west. The moat continues to the west next to the large "
          "mansion that lies to the south. A clearing lies to the north "
         "and what appears to be a bridge is off to the west.");
  SetItems( ([
        "bank" : (:GetLong:),
        "mud" : "The mud here is very sticky.",
  ({"footprints", "footprint", "tracks" }) : "These human tracks lead "
                            "west.",
        "moat" : "The water is a very interesting shade of green.",
       "water" : "The water is covered in algea.",
       "algea" : "These plants cover the moat.",
        "mansion" : "This mansion is very large.",
        "clearing" : "The clearing is north of here.",
        "bridge" : "The bridge is off to the west.",
        ]) );
  }
