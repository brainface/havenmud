#include <lib.h>
#include <domains.h>
#include "store.h"
inherit LIB_ROOM;

static void create() {
  ::create();

  SetInventory( ([
     STORE_DIR "leatherpants" : 2,     
     STORE_DIR "leathervest" : 2,     
     STORE_DIR "leatherglove" : 4,     
     STORE_DIR "leatherboots" : 2,     
     STORE_DIR "leatherhelmet" : 2,          
  ]) );
}
