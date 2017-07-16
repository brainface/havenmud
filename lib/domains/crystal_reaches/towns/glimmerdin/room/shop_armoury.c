#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetShort("shop armoury");
  SetInventory( ([
     G_OBJ "steelbreastplate" : 1,
     G_OBJ "steelhelm" : 1,
     G_OBJ "steelgauntlet" : 2,
     G_OBJ "steelboots" : 1,
     G_OBJ "steelcuisse" : 1,
     G_OBJ "hsteelbreastplate" : 1,
     G_OBJ "hsteelhelm" : 1,
     G_OBJ "hsteelgauntlet" : 2,
     G_OBJ "hsteelboots" : 1,
     G_OBJ "hsteelcuisse" : 1,
     G_OBJ "chainvest" : 1,
     G_OBJ "chainhelm" : 1,
     G_OBJ "chaingauntlet" : 2,
     G_OBJ "chainboots" : 1,
     G_OBJ "chaincuisse" : 1,
     G_OBJ "axe" : 2,
     G_OBJ "chainmail" : 1,
     G_OBJ "hammer" : 2,
     G_OBJ "flamberge" : 1,
     G_OBJ "lorica" : 1,
     G_OBJ "greaves" : 1,
     G_OBJ "copper_belt" : 2,
     STD_CRAFTING + "scrolls/iron_ingot" : 2,
     STD_CRAFTING + "scrolls/bronze_ingot" : 2,     
     STD_CRAFTING + "scrolls/mithril_ingot" : 2,
     STD_CRAFTING + "scrolls/gold_ingot" : 2,
     STD_CRAFTING + "scrolls/silver_ingot" : 2,
  ]) );
  SetExits( ([
    ]) );
}

