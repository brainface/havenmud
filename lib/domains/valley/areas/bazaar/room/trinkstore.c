//
// A storage room for the trinket booth
// Created by Athalie
//
#include <lib.h>
#include "../bazaar.h"
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
   SetNoClean(1);
   SetInventory( ([
     BAZAAR_OBJ "box" : 2,
     BAZAAR_OBJ "figurine" : 3,
   ]) );
   SetClimate("indoors");
}
