#include <lib.h>
#include <std.h>
#include "../parva.h"
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetShort("a shrine to the Drowned God");
  SetExits( ([
    "out" : PARVA_ROOM "wharf1",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetInventory( ([
    STD_LIGHT "torch" : 6,
    STD_PROJECTILE "hand_crossbow" : 2,
//    STD_STORAGE "backpack" : 2,
    STD_OBJ "fishing/pole" : 4,
    ]) );
  
}
