#include <lib.h>
#include <std.h>
#include "../tairi.h"
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetPurgeInterval(14);
  SetInventory( ([
  STD_LIGHT+"torch"               : 3,
  TAI_RI_OBJ+"tekken"             : 2,
  STD_LOCKPICKS+"picks"           : 4,
  "/domains/tairi/areas/camp/obj/katana" : 2,
  "/domains/tairi/areas/camp/obj/wakasashi" : 2,
  TAI_RI_OBJ "lotuspetal"         : 3,
  "/std/obj/fishing/pole.c"       : 1,
  TAI_RI_OBJ "oyoroi"             : 3,
  TAI_RI_OBJ "straw_hat"          : 3,
  TAI_RI_OBJ "cotton_pants"       : 3,
  TAI_RI_OBJ "plain_tanto"       : 3,
  ]) );
}

