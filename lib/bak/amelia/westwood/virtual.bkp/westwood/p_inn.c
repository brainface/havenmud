#include <lib.h>
#include "../westwood.h"

inherit LIB_PLAYER_SHOP;

static void create() {
   player_shop::create();
   SetShopId("westwood_inn");
   SetExits( ([
      "out" : V_ROOM "25,29",
   ]) );
   SetLocalCurrency("cuicui");
}
