#include <lib.h>
#include "../durgoroth.h"

inherit LIB_PLAYER_HOUSE;

static void create() {
   player_house::create();
   SetLocalCurrency("crystals");
   SetHouseId("durg_house_3");
   SetTown("durgoroth");
   SetExits( ([
    "out" : D_ROOM + "/road10",
   ]) );
}
