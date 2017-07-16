// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <std.h>
#include "../karak.h"
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetShort("Karak General Store");
  SetInventory( ([
    KARAK_OBJ + "pack" : 2,
    STD_LIGHT + "torch" : 4,
    STD_FISHING + "pole"  : 4,  
  ]) );
}
