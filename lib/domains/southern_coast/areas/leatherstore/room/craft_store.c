#include <lib.h>
#include <domains.h>
#include <std.h>
#include "../store.h"
inherit LIB_ROOM;

static void create() {
  ::create();

  SetInventory( ([
  ]) );
}

