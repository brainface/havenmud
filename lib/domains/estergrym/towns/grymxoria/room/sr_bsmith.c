#include <lib.h>
#include "../grymxoria.h"
inherit LIB_STOREROOM;


static void create() {
  storeroom::create();
  SetNoClean(1);
  SetPurgeInterval(7);
  SetInventory( ([
    G_OBJ + "nosf_sword" : 1,
    G_OBJ + "nosf_dagger" : 1,
    G_OBJ + "nosf_axe" : 1,
    G_OBJ + "nosf_lance" : 1,
    G_OBJ + "nosf_staff" : 1,
    G_OBJ + "nosf_mace" : 1,
    G_OBJ + "blood_dagger" : 1,
    G_OBJ + "blood_lance" : 1,
    G_OBJ + "blood_sword" : 1,
  ]) );
}

