#include <lib.h>
#include "../grymxoria.h"
inherit LIB_STOREROOM;


static void create() {
  storeroom::create();
  SetNoClean(1);
  SetPurgeInterval(7);
  SetInventory( ([
    G_OBJ + "guard_armour" : 2,
    G_OBJ + "wall_shield" : 2,
  ]) );
}

