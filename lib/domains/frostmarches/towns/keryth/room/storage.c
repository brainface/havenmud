// Updated for new Keryth specific tail wrap Urien 12.30.12
#include <lib.h>
#include <std.h>
#include "../keryth.h"

inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
  SetInventory( ([
    K_OBJ + "/winter_coat" : 1,
    "/std/armour/glove/leather_glove" : 2,
    K_OBJ + "/common_pants" : 3,
    K_OBJ "/blanket" : 2,
    STD_STORAGE "backpack" : 2,
    STD_CLOTHING "tailwrapgoden" : 2,
  ]) );
  SetPurgeInterval(25);
}
