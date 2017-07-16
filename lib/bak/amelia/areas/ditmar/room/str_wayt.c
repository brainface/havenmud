#include <lib.h>
inherit LIB_STOREROOM;
#include <std.h>
#include "ditmar.h"

static void create() {
   storeroom::create();
   SetInventory( ([
                    STD_LIGHT + "match" : 2,
                    STD_LIGHT + "torch" : 2,
                    STD_OBJ + "fishing/pole" : 1,
                    D_OBJ + "/robe" : 1,
               ]) );
   SetPurgeInterval(4);
}