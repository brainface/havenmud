#include <lib.h>
#include <domains.h>
#include <std.h>
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
     STORE_DIR "clothpants" : 2,
     STD_STORAGE "backpack" : 2,
     STD_STORAGE "scabbard" : 3,     
     STORE_DIR "clothshirt" : 2,
     STORE_DIR "clothglove" : 4,
     STORE_DIR "clothsock" : 2,
     STORE_DIR "clothhelmet" : 2,
     STORE_DIR "clothbelt" : 2,
  ]) );
}

