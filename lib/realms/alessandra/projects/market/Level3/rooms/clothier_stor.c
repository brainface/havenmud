//  Malv Clothier Storage
//  Alessandra 2009

#include <lib.h>
#include <std.h>
#include "../mal.h"
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();

  SetInventory( ([
     MAL_OBJ3 + "slippers" : 1,
     MAL_OBJ3 + "satin_gown" : 1,
     MAL_OBJ3 + "han_shirt" : 2,
     ]) );
  SetPurgeInterval(4);

}
