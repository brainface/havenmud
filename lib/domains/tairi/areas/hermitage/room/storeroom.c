#include <lib.h>
#include <std.h>
#include "../herm.h"
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetPurgeInterval(14);
  SetInventory( ([
    HERM_OBJ "blunt" : 2,
    HERM_OBJ "hack" : 2,
    HERM_OBJ "knife" : 2,
    HERM_OBJ "pierce" : 2,
    HERM_OBJ "projectile" : 2,
    HERM_OBJ "slash" : 2,
    HERM_OBJ "staff" : 2,
  ]) );
}
