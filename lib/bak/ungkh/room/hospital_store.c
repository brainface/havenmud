#include <lib.h>
#include "../ungkh.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetNoClean(1);

  SetInventory( ([
    U_OBJ + "red_shroom" : 2,
    U_OBJ + "blue_shroom" : 2,
    U_OBJ + "green_shroom" : 2,
    U_OBJ + "yellow_shroom" : 2,
    U_OBJ + "gornash_root" : 2,
    ]) );
  }
