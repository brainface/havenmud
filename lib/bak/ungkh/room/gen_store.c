#include <lib.h>
#include "../ungkh.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetNoClean(1);

  SetInventory( ([
    "/std/armour/glove/leather_glove" : 2,
    "/std/armour/shield/shield_wooden" : 2,
    "/std/armour/shirt/vest_leather" : 2,
    "/std/armour/boot/boots_leather" : 2,
    ]) );
  }
