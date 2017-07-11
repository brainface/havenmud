/* a player run inn */
#include <lib.h>
#include "../grymxoria.h"
inherit LIB_PLAYER_SHOP;

static void create()
{
  player_shop::create();
  SetShopId("grymxoria_inn_1");
  SetExits(  ([
    "out" : G_ROOM "road4",
  ])  );
  SetTown("Grymxoria");
  SetLocalCurrency("bloodgems");
}
