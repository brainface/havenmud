// Dalnairn
// Aerelus

#include <lib.h>
#include <std.h>
#include "../../dalnairn.h"
inherit LIB_STOREROOM;

static void create() {
   storeroom::create();
   SetInventory( ([
     DAL_OBJ "shield" : 4,
     DAL_OBJ "guardarmour" : 2,
     DAL_OBJ "sword" : 3,     
   ]) );
   SetPurgeInterval(3);
}