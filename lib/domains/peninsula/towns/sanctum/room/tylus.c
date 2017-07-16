#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetAmbientLight(40);
  SetWarmth(50);
  SetClimate("indoors");
  SetShort("Tylus' of Sanctum");
  SetExits( ([
    "out" : ROME_ROOM "bazaar",
    ]) );
  SetLong("Within the tent of Tylus of Sanctum, order and neatness "
          "reign. His tent contains little out of place, and a small "
          "counter serves as the simple method of exchange between "
          "owner and client. Outside, the Sanctum Bazaar spreads "
          "in all its glory.");
  SetSmell( ([
    "default" : "The tent smells of exotic spices and cured hides.",
    ]) );
  SetListen( ([
    "default" : "Haggling merchants and loud vendors can be heard "
                "from outside.",
    ]) );
  SetInventory( ([
    ROME_NPC "tylus" : 1,
  ROME_NPC "cerasys" : 1,
    ROME_OBJ "chest" : 1,
    ]) );
}
