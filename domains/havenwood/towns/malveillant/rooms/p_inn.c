/* a player run inn */
#include <lib.h>
#include "../mal.h"
inherit LIB_PLAYER_SHOP;

static void create()
{
  player_shop::create();
  SetShopId("mal_inn_1");
  SetExits(  ([
    "out" : MAL_ROOMS "path9",
  ])  );
  SetTown("Malveillant");
  SetLocalCurrency("roni");
}
