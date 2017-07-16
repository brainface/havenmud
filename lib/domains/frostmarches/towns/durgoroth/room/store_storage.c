#include <lib.h>
#include <std.h>
#include "../durgoroth.h"
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetPurgeInterval(14);
  SetInventory( ([
    STD_LIGHT "torch" : 4,
    DURG_OBJ "scale_robe" : 2,
    DURG_OBJ "cit_chain" : 2,
    DURG_OBJ "horseshoe" : 4,
    DURG_OBJ "bone_horseshoe" : 4,
    DURG_OBJ "duster" : 4,
    DURG_OBJ "newb_chain" : 2,
    "/std/weapon/melee/brass_knuckles" : 4,
    "/std/weapon/hack/meat_hook" : 2,
  ]) );
}
