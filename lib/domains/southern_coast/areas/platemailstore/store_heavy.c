#include <lib.h>                                        
#include <domains.h>                                    
#include "store.h"
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetShort("kelan's shop");
  SetInventory( ([
     STORE_DIR "hsteelbreastplate" : 3,
     STORE_DIR "hsteelhelm" : 3,
     STORE_DIR "hsteelgauntlet" : 6,
     STORE_DIR "hsteelboots" : 3,
     STORE_DIR "hsteelcuisse" : 3,
  ]) );
  SetExits( ([
    ]) );
}

