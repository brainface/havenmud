//  Possible future use
//  Storage for Hat Vendor
//  Alessandra 2009

#include <lib.h>
#include <std.h>
#include "../mal.h"
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();

  SetInventory( ([
     ]) );
  SetPurgeInterval(4);

}