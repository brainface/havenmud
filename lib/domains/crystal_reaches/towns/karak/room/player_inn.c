// Karak
// Rewritten by Laoise
// May 2006

#include <lib.h>
#include "../karak.h"
inherit LIB_PLAYER_SHOP;

static void create() {
  player_shop::create();
  SetShopId("karak_inn");
  //SetDomain("Crystal Reaches");
  SetTown("Karak");
  SetLocalCurrency("orcteef");
  SetExits( ([
    "out" : KARAK_ROOM + "rd7",
  	]) );
}
