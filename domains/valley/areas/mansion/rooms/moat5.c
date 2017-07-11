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
       "north" : MANSION_ROOMS + "clearing7",
       "east" : MANSION_ROOMS + "moat6",
       "northeast" : MANSION_ROOMS + "clearing8",
       "northwest" : MANSION_ROOMS + "clearing6",
          ]) );
  SetListen( ([
        "default" : "Barking dogs can be heard in the distance.",
            ]) );
  SetSmell( ([
        "default" : "The stench of the stagnant water is overwhelming.",
           ]) );
  SetLong("The bank of the moat is a steep slope here and is a bit "
          "more stable then other sections of the bank. To the north lies "
         "a small clearing. A large mansion lies across the moat to the "
         "south, and there is a bridge to the west. The moat continues off "
         "to the west.");
  SetItems( ([
        "bank" : (:GetLong:),
        "moat" : "The stagnant water is covered in green plants.",
        "water" : "This water is covered in plants.",
    ({"plants", "plant"}) : "This is algea.",
        "algea" : "These plants cover the surface of the moat.",
        "surface" : "The surface of the moat is very green.",
         "slope" : "The slope is quite steep and leads to the north.",
         "clearing" : "The clearing lies to the north.",
    ({"mansion", "dwelling"}) : "This large dwelling lies across the moat "
                                "to the south.",
         "bridge" : "This bridge sits very close to the surface of the "
                     "moat and would be impossible to fit underneath.",
            ]) );
  }
