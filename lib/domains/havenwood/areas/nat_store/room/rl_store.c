#include <lib.h>
#include <domains.h>
#include "../nat_store.h"
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetShort("constanza's storage");
  SetInventory( ([
    NAT_STORE_OBJ "rl_boots"    : 1,
    NAT_STORE_OBJ "rl_hat"      : 1,
    NAT_STORE_OBJ "rl_shield"   : 1,
    NAT_STORE_OBJ "rl_glove"    : 2,
    NAT_STORE_OBJ "rl_pants"    : 1,
    NAT_STORE_OBJ "rl_cuirass"  : 1,
  ]) );
}

