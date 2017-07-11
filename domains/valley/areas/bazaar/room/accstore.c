//
// a storage room for the accessories booth
// Created by Athalie
//
#include <lib.h>
#include "../bazaar.h"
#include "../bazaar.h"
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
   SetNoClean(1);
   SetInventory( ([
     BAZAAR_OBJ + "silver_ring" : 1,
     BAZAAR_OBJ + "scarf" : 2,
     BAZAAR_OBJ + "velvet_hat" : 2,
   ]) );
   SetClimate("indoors");
}
