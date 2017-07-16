#include <lib.h>
#include "../westwood.h"

inherit LIB_PLAYER_HOUSE;

static void create() {
   player_house::create();
   SetLocalCurrency("cuicui");
   SetHouseId("westwood_house_4");
   SetExits( ([
      "out" : "26,14",
   ]) );
}
