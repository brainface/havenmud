#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../rome.h"
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetClimate("indoor");
  SetInventory( ([
    STD_FISH "oceanpole" : 2,
    ROME_OBJ "epicks" : 1,
    ROME_OBJ "gpicks" : 1,
    ROME_OBJ "spicks" : 1,
//    STD_STORAGE "backpack" : 2,
    ]) );
}
