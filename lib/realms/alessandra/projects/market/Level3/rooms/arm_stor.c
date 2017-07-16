//  Malv Armoury Storage
//  Updated by Alessandra 2009

#include <lib.h>
#include <std.h>
#include "../mal.h"
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
  
  SetInventory( ([
    STD_ARMOUR + "pants/leggings" : 2,
    STD_ARMOUR + "shirt/breastplate" : 1,
    STD_ARMOUR + "shirt/flannelshirt" : 4,
    STD_CLOTHING + "boot/boot" : 3,
    ]) );
  SetPurgeInterval(3);

}
