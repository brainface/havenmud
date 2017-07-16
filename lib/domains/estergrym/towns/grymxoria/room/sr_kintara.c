
#include <lib.h>
#include <std.h>
//#include "../grymxoria.h"

inherit LIB_STOREROOM;

static void create() {
   storeroom::create();
   SetInventory( ([
    STD_STORAGE "backpack" : 2,
     STD_LIGHT "torch" : 8,
     STD_FISH "pole" : 2,
     STD_OBJ "digging/shovel" : 1,
   ]) );
   SetPurgeInterval(1);
}
