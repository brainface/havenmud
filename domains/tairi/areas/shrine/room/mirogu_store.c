
#include <lib.h>
#include <std.h>
#include "../shrine.h"
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetPurgeInterval(14);
  SetInventory( ([
  ]) );
}
