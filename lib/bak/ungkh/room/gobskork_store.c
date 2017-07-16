#include <lib.h>
#include "../ungkh.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetNoClean(1);

  SetInventory( ([
    ]) );
  }
