// Coded by Zeratul
// 3-22-2000

#include <lib.h>
#include <std.h>
#include "../../vacazar.h"

inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
  SetPurgeInterval(2);
  SetInventory( ([
     STD_WEAPON "knife/stiletto" : 4,
  ]) );
}
