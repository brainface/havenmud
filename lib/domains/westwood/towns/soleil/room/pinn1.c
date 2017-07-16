#include <lib.h>
#include "../soleil.h"
inherit LIB_PLAYER_SHOP;

static void create() {
   player_shop::create();
   SetShopId("soleilinn1");
   SetExits( ([
                "out" : S_ROOM + "up5",
           ]) );
   SetTown("Soleil");
   SetLocalCurrency("cuicui");
}
