/*  A player run inn */
#include <lib.h>
inherit LIB_PLAYER_HOUSE;

static void create() {
  player_house::create();
  SetHouseId("work_house");
  SetExits( ([
     "out" : "/realms/duuktsaryth/stuff/offroom",
    ]) );
  }
