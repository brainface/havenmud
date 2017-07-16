//  Malv Clothier Storage
//  Alessandra 2009

#include <lib.h>
#include <std.h>
#include "../mal.h"
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();

  SetInventory( ([
     MAL_OBJ3 + "clth_slippers" : 1,
     MAL_OBJ3 + "clth_satingown" : 1,
     MAL_OBJ3 + "clth_handsomeshirt" : 2,
     MAL_OBJ3 + "clth_blkglove" : 1,
     MAL_OBJ3 + "clth_butteredboot" : 1,
     MAL_OBJ3 + "clth_carminejerkin" : 1,
     MAL_OBJ3 + "clth_fittedpants" : 1,
     ]) );
  SetPurgeInterval(4);

}
