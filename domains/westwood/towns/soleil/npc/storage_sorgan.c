#include <lib.h>
#include <std.h>
inherit LIB_STOREROOM;
#include "../soleil.h"

static void create() {
   storeroom::create();
   SetInventory( ([
                    STD_LIGHT + "torch" : 4,
                    STD_FISH "pole" : 2,
               ]) );
   SetPurgeInterval(1);
}

