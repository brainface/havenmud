#include <lib.h>
inherit LIB_STOREROOM;
#include "../castle.h"

static void create() {
   storeroom::create();
   SetInventory( ([
               ]) );
   SetPurgeInterval(2);
}
