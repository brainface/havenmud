#include <lib.h>
#include <std.h>
inherit LIB_STOREROOM;
#include "parva.h"

static void create() {
   storeroom::create();
   SetInventory( ([
               ]) );
   SetPurgeInterval(5);
}
