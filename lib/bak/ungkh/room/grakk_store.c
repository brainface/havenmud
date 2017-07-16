#include <lib.h>
#include "../ungkh.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetNoClean(1);

  SetInventory( ([
    U_OBJ + "scythe" : 2,
    U_OBJ + "gob_knife" : 2,
    U_OBJ + "javelin" : 2,
    ]) );
  }
