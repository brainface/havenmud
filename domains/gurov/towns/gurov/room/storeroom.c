#include <lib.h>
#include <std.h>
inherit LIB_STOREROOM;

static void create() {
  SetInventory( ([
    STD_FISHING "pole"  : 2,
    STD_LIGHT   "torch" : 6,
    STD_STORAGE "backpack" : 2,
    ]) );
  SetPurgeInterval(2);
}
