#include <lib.h>
#include "../glim.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetInventory( ([
    G_OBJ + "greaves": 1,
    G_OBJ + "lorica": 1,
    G_OBJ + "copper_belt": 1,
                   ]) );
  }
