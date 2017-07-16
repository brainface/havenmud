#include <lib.h>
#include <domains.h>
#include "../nat_store.h"
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetShort("talamar's storage");
  SetInventory( ([
    NAT_STORE_OBJ "nat_boots"    : 1,
    NAT_STORE_OBJ "nat_helm"     : 1,
    NAT_STORE_OBJ "nat_shield"   : 1,
    NAT_STORE_OBJ "nat_glove"    : 2,
    NAT_STORE_OBJ "nat_leggings" : 1,
    NAT_STORE_OBJ "nat_shirt"    : 1,
  ]) );
}

