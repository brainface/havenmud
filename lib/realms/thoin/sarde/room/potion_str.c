#include <lib.h>
#include "../sarde.h"
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
  SetInventory( ([
              ]) );
  SetPurgeInterval(3);
 }
