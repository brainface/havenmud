//Selket@Haven
//2006
#include <lib.h>
#include "../ungkh.h"
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetShort("shop storage, slut");
  SetInventory( ([
    U_OBJ "blue_shroom" : 3,
    U_OBJ "green_shroom" : 3,
    U_OBJ "yellow_shroom" : 3,
    U_OBJ "red_shroom" : 3,
    U_OBJ "gornash_root" : 2,
    U_OBJ "borgla_sap" : 2,
  ]) );
  SetExits( ([
  ]) );
}
