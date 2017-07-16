#include <lib.h>
#include "../durgoroth.h"

inherit LIB_PLAYER_HOUSE;

static void create() {
   player_house::create();
   SetLocalCurrency("crystals");
   SetTown("durgoroth");
   SetHouseId("durg_house_1");
   SetExits( ([
   "out" : D_ROOM + "/road05.c",
   ]) );
}
