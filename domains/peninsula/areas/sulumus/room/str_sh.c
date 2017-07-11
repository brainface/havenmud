#include <lib.h>
#include "../sulumus.h"

inherit LIB_STOREROOM;

static void create() {
   storeroom::create();
   SetPurgeInterval(3);
   SetInventory( ([
   ]) );
}
