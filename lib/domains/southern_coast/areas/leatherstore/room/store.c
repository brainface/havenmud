#include <lib.h>
#include <domains.h>
#include <std.h>
#include "../store.h"
inherit LIB_ROOM;

static void create() {
  ::create();

  SetInventory( ([
     LSTORE_OBJ "leatherpants" : 2,
     LSTORE_OBJ "leathervest" : 2,
     LSTORE_OBJ "leatherglove" : 4,
     LSTORE_OBJ "leatherboots" : 2,
     LSTORE_OBJ "leatherhelmet" : 2,
     LSTORE_OBJ "clothpants" : 2,
     LSTORE_OBJ "clothshirt" : 2,
     LSTORE_OBJ "clothglove" : 4,
     LSTORE_OBJ "clothsock" : 2,
     LSTORE_OBJ "clothhelmet" : 2,
     LSTORE_OBJ "clothbelt" : 2,
     STD_STORAGE "backpack" : 2,
     STD_STORAGE "scabbard" : 3,         
  ]) );
}

