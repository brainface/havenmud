#include <lib.h>
#include <std.h>
#include "../grymxoria.h"
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();
  SetPurgeInterval(7);
  SetNoClean(1);
  SetProperty("storage room",1);
  SetInventory( ([
    STD_LIGHT + "match" : 4,
    STD_LIGHT + "torch" : 2,
    STD_FISHING + "pole" : 2,
  ]) );
}
