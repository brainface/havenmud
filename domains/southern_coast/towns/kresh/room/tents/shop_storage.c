/*  Storage Room */
#include <lib.h>
#include "../../goblins.h"
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
  SetNoClean(1);
  SetInventory( ([
     GOBLIN_OBJ + "sap" : 2,
      ]) );
  }
