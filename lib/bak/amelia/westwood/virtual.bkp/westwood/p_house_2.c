#include <lib.h>
#include "../westwood.h"

inherit LIB_PLAYER_HOUSE;

static void create() {
   player_house::create();
   SetLocalCurrency("imperials");
   SetHouseId("westwood_house_2");
   SetExits( ([
      "out" : "/domains/westwood/virtual/westwood/25,29",
   ]) );
}
