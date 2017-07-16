#include <lib.h>
#include <std.h>
#include "../path.h"

inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetShort("shop storage");
  SetInventory( ([
		STD_LIGHT "torch" : 5,
		G_OBJ "shovel"    : 2,
		G_OBJ "pick"      : 2,	        
  ]) );
  SetExits( ([
    ]) );
}
