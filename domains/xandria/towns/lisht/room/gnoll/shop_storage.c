//Selket@Haven
//2006
#include <lib.h>
#include "../../lisht.h"
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetShort("shop storage");
  SetInventory( ([
    LISHT_OBJ "mace" : 1,
    LISHT_OBJ "gohome_vial" : 1,
    LISHT_OBJ "knife"    : 1,
    LISHT_OBJ "lamp"     : 1,
    LISHT_OBJ "khopesh"  : 1,
    LISHT_OBJ "trowel" : 1,
    LISHT_OBJ "staff" : 1,
    LISHT_OBJ "newbie_pole"  : 1,
    LISHT_OBJ "shenti"  : 1,
    LISHT_OBJ "ldress"  : 1,
   ]) );
  SetExits( ([
    ]) );
}

