#include <lib.h>
#include <domains.h>
#include "store.h"
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetShort("kelan platemail's shop");
  SetInventory( ([
     STORE_DIR "steelbreastplate" : 3,
     STORE_DIR "steelhelm" : 3,
     STORE_DIR "steelgauntlet" : 6,
     STORE_DIR "steelboots" : 3,
     STORE_DIR "steelcuisse" : 3,
     STORE_DIR "lwallshield" : 2,
  ]) );
  SetExits( ([
    ]) );
}

