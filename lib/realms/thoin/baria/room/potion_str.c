#include <lib.h>
#include "../jungle.h"
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
  SetInventory( ([
              ]) );
  SetPurgeInterval(3);
 }
