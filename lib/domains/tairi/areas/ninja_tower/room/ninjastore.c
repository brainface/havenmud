#include <lib.h>
#include <std.h>
#include "../ninja.h"
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetPurgeInterval(14);
  SetInventory( ([
  STD_LOCKPICKS "picks"   : 4,
  N_STORE "ashiaro" : 4,
  N_STORE "jikatabi" : 4,
  N_STORE "mastershozoku" : 2,
  N_STORE "sanjakutenugui" : 2,
  N_STORE "sleeve" : 4,
  N_STORE "suntetsu" : 4,
  N_OBJ "shozoku" : 2,
  N_OBJ "kusarigama" : 2,
  N_OBJ "ninjato" : 2,
  N_STORE "obi" : 2,
  N_STORE "randoseru" : 2,
  N_STORE "boshuriken" : 4,
  N_STORE "hirashuriken" : 4,
  ]) );
}
