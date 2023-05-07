//mahkefel 2010
// heavy armour store for arcanith
#include <lib.h>
#include <domains.h>
#include <std.h>
#include "../../ruins.h"
inherit LIB_ROOM;

static void create() {
  ::create();

  SetInventory( ([
    OBJ "/plate_breastplate" : 1,
    OBJ "/plate_horseshoe"   : 2,
    OBJ "/plate_helm"        : 1,
    OBJ "/plate_cuisse"      : 1,
    OBJ "/small_shield"      : 1,
    OBJ "/chainmail"         : 2,
  ]) );
}

