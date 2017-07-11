// Dalnairn
// Aerelus

#include <lib.h>
#include <std.h>
#include "../../dalnairn.h"
inherit LIB_STOREROOM;

static void create() {
   storeroom::create();
   SetInventory( ([
     
     STD_LIGHT "torch" : 8,
     STD_OBJ "digging/shovel" : 1,
   ]) );
   SetPurgeInterval(3);
}