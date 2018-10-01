// by Dahaka
// Aug 2004

#include <lib.h>
#include <std.h>
#include "../../drazh.h"

inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
  SetPurgeInterval(7);
  SetInventory( ([
     V_OBJ + "sack"        : 2,
     V_OBJ + "hooded_robe" : 2,
     ]) );
}
