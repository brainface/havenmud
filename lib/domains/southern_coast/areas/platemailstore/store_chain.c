#include <lib.h>
#include <domains.h>
#include "store.h"
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetShort("kelan's chainmail shop");
  SetInventory( ([
     STORE_DIR "chainvest" : 3,
     STORE_DIR "chainhelm" : 3,
     STORE_DIR "chaingauntlet" : 6,
     STORE_DIR "chainboots" : 3,
     STORE_DIR "chaincuisse" : 3,
  ]) );
  SetExits( ([
    ]) );
}

