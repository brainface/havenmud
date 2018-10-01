/* a player run inn */
#include <lib.h>
#include "../../dalnairn.h"
inherit LIB_PLAYER_SHOP;

static void create()
{
  player_shop::create();
  SetShopId("dalnairn_inn_1");
  SetExits(  ([
    "out" : DAL_ROOM "2,-2",
  ])  );
  SetTown("Dalnairn");
  SetLocalCurrency("shards");
}
