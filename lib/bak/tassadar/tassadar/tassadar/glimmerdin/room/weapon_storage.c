#include <lib.h>
#include "../glim.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetInventory( ([
    G_OBJ + "copper_axe" : 2,
    G_OBJ + "flamberge" : 1,
    G_OBJ + "hooked_axe" : 1,
    G_OBJ + "war_hammer" : 1,
    ]) );
  }
