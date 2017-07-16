//mahkefel 2010
// general store inventory for arcanith
// current vendor has unworking inventory mule,
//  making shop not work while mule is dead might be neat.
#include <lib.h>
#include <domains.h>
#include <std.h>
#include "../../ruins.h"
inherit LIB_ROOM;

static void create() {
  ::create();

  SetInventory( ([
    OBJ "/sack" : 1,
    STD_LIGHT "torch": 3,
    STD_KNIFE "pocket_knife" : 2,
    STD_POLE "staff" : 1,
    STD_LOCKPICKS "picks" : 1,
    OBJ "/pickaxe" : 1,
  ]) );
}
