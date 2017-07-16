/*  Portia  10-24-98
    The Armoury storeroom
*/

#include <lib.h>
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
  SetInventory( ([
      "/std/armour/pants/leggings" : 2,
      "/std/armour/shirt/breastplate" : 1,
      "/std/armour/shirt/flannelshirt" : 4,
      "/std/clothing/boot/boot" : 3,
        ]) );
  SetPurgeInterval(3);
  }
