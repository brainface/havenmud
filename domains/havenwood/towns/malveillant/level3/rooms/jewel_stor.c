//  Jewelry Store Storage
//  Alessandra 2009

#include <lib.h>
#include <std.h>
#include "../mal.h"
inherit LIB_STOREROOM;

static void create() {
  storeroom::create();

  SetInventory( ([
     MAL_OBJ + "/clothing/elf_medallion" : 2,
     MAL_OBJ3 + "jwlr_goldring" : 2,
     STD_CRAFTING + "scrolls/silver_ingot" : 2,
     STD_CRAFTING + "scrolls/gold_ingot" : 2,     
     STD_CRAFTING + "scrolls/silver_ruby_small" : 2,
     ]) );
  SetPurgeInterval(4);

}

