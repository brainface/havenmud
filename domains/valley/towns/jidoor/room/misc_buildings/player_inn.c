//
// A player owned inn
// Created by Zaxan@Haven
//

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_PLAYER_SHOP;

static void create() {
   player_shop::create();
   SetShopId("jidoor_inn_1");
   SetExits( ([ 
      "west" : JID_ROOM "/misc_buildings/inn",
      "out" : JID_ROOM "/road5",
   ]) );
   SetTown("Jidoor");
   SetLocalCurrency("rupies");
}
