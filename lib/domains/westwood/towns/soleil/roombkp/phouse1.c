#include <lib.h>
#include "../soleil.h"
inherit LIB_PLAYER_HOUSE;

static void create() {
   ::create();
   SetLocalCurrency("cuicui");
   SetHouseId("soleil_house_one");
   SetTown("Soleil");
   SetExits( ([
                "out" : S_ROOM + "up4",
           ]) );
}
