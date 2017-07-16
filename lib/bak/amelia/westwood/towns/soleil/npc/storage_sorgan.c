#include <lib.h>
#include <std.h>
inherit LIB_STOREROOM;
#include "../soleil.h"

static void create() {
   storeroom::create();
   SetInventory( ([
                    STD_LIGHT + "match" : 1,
                    STD_LIGHT + "torch" : 1,
                    STD_FISH "pole" : 2,
               ]) );
   SetPurgeInterval(1);
}
